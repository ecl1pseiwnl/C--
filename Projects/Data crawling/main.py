from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
from bs4 import BeautifulSoup
import time
import random
import json
import pandas as pd
from datetime import datetime
import os
import glob

def create_driver_with_webdriver_manager():
    """
    Tạo driver sử dụng webdriver-manager.
    Thư viện này sẽ tự động tải và sử dụng đúng phiên bản ChromeDriver,
    giúp tránh lỗi không tương thích.
    """
    options = Options()
    
    # Các tham số giúp tránh bị phát hiện là bot
    options.add_argument('--no-sandbox')
    options.add_argument('--disable-dev-shm-usage')
    options.add_argument('--disable-gpu')
    options.add_argument('--disable-blink-features=AutomationControlled')
    options.add_experimental_option('excludeSwitches', ['enable-automation'])
    options.add_experimental_option('useAutomationExtension', False)
    options.add_argument('--start-maximized')

    # User-Agent ngẫu nhiên để tránh bị chặn
    user_agents = [
        'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/149.0.0.0 Safari/537.36',
        'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/148.0.0.0 Safari/537.36',
    ]
    options.add_argument(f'--user-agent={random.choice(user_agents)}')

    # Tự động quản lý driver
    service = Service(ChromeDriverManager().install())
    driver = webdriver.Chrome(service=service, options=options)

    # Ẩn dấu hiệu automation bằng CDP command
    driver.execute_cdp_cmd('Page.addScriptToEvaluateOnNewDocument', {
        'source': '''
            Object.defineProperty(navigator, 'webdriver', {
                get: () => undefined
            });
        '''
    })
    return driver

def human_like_typing(element, text):
    """Gõ text với tốc độ giống người để tránh bị phát hiện."""
    for char in str(text):
        element.send_keys(char)
        time.sleep(random.uniform(0.05, 0.15))

def click_search_button(driver):
    """Thử nhiều cách để click nút 'Xem kết quả' một cách bền vững."""
    print("🔍 Đang tìm nút 'Xem kết quả'...")
    time.sleep(1)  # Chờ trang ổn định

    # Danh sách các cách tìm và click nút
    methods = [
        lambda: WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.XPATH, "//button[contains(text(), 'Xem kết quả')]"))
        ),
        lambda: driver.find_element(By.CSS_SELECTOR, 'button[type="submit"]'),
        lambda: next(btn for btn in driver.find_elements(By.TAG_NAME, 'button') 
                     if any(keyword in btn.text.lower() for keyword in ['xem', 'tìm', 'search'])),
    ]

    for i, method in enumerate(methods, 1):
        try:
            btn = method()
            driver.execute_script("arguments[0].scrollIntoView({behavior: 'smooth', block: 'center'});", btn)
            time.sleep(0.5)
            driver.execute_script("arguments[0].click();", btn)
            print(f"✅ Cách {i}: Click thành công")
            return True
        except Exception as e:
            print(f"❌ Cách {i} thất bại: {e}")
    
    # Phương án cuối: Nhấn phím Enter
    try:
        input_box = driver.find_element(By.CSS_SELECTOR, 'input[type="text"]')
        input_box.send_keys(Keys.RETURN)
        print("✅ Click bằng phím Enter")
        return True
    except Exception as e:
        print(f"❌ Tất cả cách đều thất bại: {e}")
        return False

def doc_diem_tu_file_html(file_path):
    """
    Đọc điểm từ file HTML đã lưu
    Returns: (ket_qua_dict, thanh_cong)
    """
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            html_content = f.read()
        
        soup = BeautifulSoup(html_content, 'html.parser')
        subjects = soup.find_all('div', class_='tc-cd-sub')
        
        if subjects:
            ket_qua = {}
            for sub in subjects:
                ten_mon = sub.find('span', class_='sub-name')
                diem = sub.find('strong', class_='sub-score')
                data_score = sub.get('data-score', 'N/A')
                if ten_mon and diem:
                    ten = ten_mon.text.strip()
                    diem_so = diem.text.strip()
                    ket_qua[ten] = {'diem': diem_so, 'data_score': data_score}
            return ket_qua, True
        else:
            return None, False
    except Exception as e:
        print(f"❌ Lỗi đọc file HTML: {e}")
        return None, False

def kiem_tra_file_html_sbd(sbd):
    """
    Kiểm tra xem đã có file HTML cho SBD này chưa
    Returns: (file_path, exists)
    """
    # Kiểm tra các file có tên chuẩn
    pattern = f'ket_qua_{sbd}.html'
    if os.path.exists(pattern):
        return pattern, True
    
    # Kiểm tra các file debug
    debug_pattern = f'debug_{sbd}_*.html'
    debug_files = glob.glob(debug_pattern)
    if debug_files:
        # Lấy file debug mới nhất
        debug_files.sort(key=os.path.getmtime, reverse=True)
        return debug_files[0], True
    
    return None, False

def tra_cuu_diem(sbd, max_retries=5, check_html_first=True):
    """
    Hàm chính để tra cứu điểm cho một SBD.
    Tự động thử lại nếu thất bại.
    
    Args:
        sbd: Số báo danh cần tra
        max_retries: Số lần thử tối đa
        check_html_first: Kiểm tra file HTML đã có trước khi crawl
    
    Returns:
        (ket_qua, file_name, thanh_cong, tu_file)
    """
    
    # 1. Kiểm tra file HTML đã có
    if check_html_first:
        file_path, exists = kiem_tra_file_html_sbd(sbd)
        if exists:
            print(f"📂 Đã tìm thấy file HTML cho SBD {sbd}: {file_path}")
            ket_qua, thanh_cong = doc_diem_tu_file_html(file_path)
            if thanh_cong and ket_qua:
                print(f"✅ Đọc dữ liệu từ file HTML thành công!")
                print(f"\n📊 KẾT QUẢ SBD: {sbd} (từ file HTML)")
                print("="*60)
                for mon, info in ket_qua.items():
                    print(f"• {mon}: {info['diem']} (data-score: {info['data_score']})")
                return ket_qua, file_path, True, True
            else:
                print(f"⚠️ File HTML tồn tại nhưng không có dữ liệu điểm, sẽ crawl lại...")
    
    # 2. Crawl từ web nếu chưa có file hoặc file không có dữ liệu
    print(f"🌐 Tiến hành crawl từ web cho SBD {sbd}...")
    
    for attempt in range(1, max_retries + 1):
        driver = None
        try:
            print(f"\n🔄 Lần thử {attempt}/{max_retries} cho SBD {sbd}")
            
            driver = create_driver_with_webdriver_manager()
            print(f"\n🔍 Tra cứu SBD: {sbd}")

            # 1. Mở trang tra cứu
            driver.get('https://diemthi.vnexpress.net/')
            print("⏳ Đang tải trang chủ...")
            time.sleep(random.uniform(2, 4))

            # 2. Tìm và nhập SBD
            input_box = WebDriverWait(driver, 15).until(
                EC.presence_of_element_located((By.CSS_SELECTOR, 'input[type="text"]'))
            )
            input_box.clear()
            human_like_typing(input_box, str(sbd))
            print(f"✅ Đã nhập SBD: {sbd}")

            # 3. Click nút tìm kiếm
            if not click_search_button(driver):
                print(f"❌ Lần thử {attempt}: Không thể click nút tìm kiếm")
                driver.quit()
                continue

            # 4. Chờ kết quả load
            print("⏳ Đang tải kết quả...")
            time.sleep(random.uniform(8, 10))
            
            # 5. Lấy HTML của trang kết quả
            html_content = driver.page_source
            file_name = f'ket_qua_{sbd}.html'
            with open(file_name, 'w', encoding='utf-8') as f:
                f.write(html_content)
            print(f"💾 Đã lưu HTML: {file_name}")
            
            # 6. Đọc điểm từ file vừa lưu
            ket_qua, thanh_cong = doc_diem_tu_file_html(file_name)
            
            if thanh_cong and ket_qua:
                print(f"\n📊 KẾT QUẢ SBD: {sbd}")
                print("="*60)
                for mon, info in ket_qua.items():
                    print(f"• {mon}: {info['diem']} (data-score: {info['data_score']})")
                driver.quit()
                return ket_qua, file_name, True, False
            else:
                print(f"❌ Lần thử {attempt}: KHÔNG TÌM THẤY ĐIỂM!")
                # Lưu HTML debug
                #debug_file = f'debug_{sbd}_attempt_{attempt}.html'
                #with open(debug_file, 'w', encoding='utf-8') as f:
                #    f.write(html_content)
                #print(f"💾 Đã lưu HTML debug: {debug_file}")
                driver.quit()
                
                if attempt == max_retries:
                    return None, file_name, False, False
                else:
                    print(f"⏳ Chờ {attempt * 2} giây trước khi thử lại...")
                    time.sleep(attempt * 2)
                    continue

        except Exception as e:
            print(f"❌ Lần thử {attempt} - Lỗi nghiêm trọng: {e}")
            if driver:
                driver.save_screenshot(f'error_{sbd}_attempt_{attempt}.png')
                driver.quit()
            
            if attempt == max_retries:
                return None, None, False, False
            else:
                print(f"⏳ Chờ {attempt * 2} giây trước khi thử lại...")
                time.sleep(attempt * 2)
                continue
    
    return None, None, False, False

def doc_tu_file_html(file_path):
    """
    Đọc điểm từ file HTML đã lưu (dùng để debug)
    """
    ket_qua, thanh_cong = doc_diem_tu_file_html(file_path)
    if thanh_cong and ket_qua:
        print(f"\n📊 ĐỌC TỪ FILE: {file_path}")
        print("="*60)
        for mon, info in ket_qua.items():
            print(f"• {mon}: {info['diem']} (data-score: {info['data_score']})")
        return ket_qua
    else:
        print(f"❌ Không tìm thấy điểm trong file {file_path}")
        return None

# --- Phần chạy chính ---
if __name__ == "__main__":
    print("="*60)
    print("🔧 TRA CỨU ĐIỂM THI THPT 2026 (HỖ TRỢ FILE HTML)")
    print("="*60)
    
    # Nhập danh sách SBD hoặc khoảng
    print("\n📝 HƯỚNG DẪN:")
    print("  - Nhập một SBD: 96001013")
    print("  - Nhập nhiều SBD cách nhau bởi dấu phẩy: 96001013,96001014,96001015")
    print("  - Nhập khoảng SBD: 96000001-96000010")
    print("  - Để trống để dùng SBD mặc định: 96001013")
    print("  - Nhập 'file' để đọc từ file HTML đã lưu")
    print("  - Nhập 'check' để kiểm tra file HTML đã có của một SBD")
    
    sbd_input = input("\n📝 Nhập SBD: ").strip()
    
    # Xử lý trường hợp đọc từ file
    if sbd_input.lower() == 'file':
        file_path = input("Nhập đường dẫn file HTML: ").strip()
        if os.path.exists(file_path):
            doc_tu_file_html(file_path)
        else:
            print(f"❌ Không tìm thấy file: {file_path}")
        exit()
    
    # Xử lý trường hợp kiểm tra file
    if sbd_input.lower() == 'check':
        sbd_check = input("Nhập SBD cần kiểm tra: ").strip()
        try:
            sbd_check = int(sbd_check)
            file_path, exists = kiem_tra_file_html_sbd(sbd_check)
            if exists:
                print(f"✅ Đã tìm thấy file HTML cho SBD {sbd_check}: {file_path}")
                # Hỏi có muốn đọc không
                read = input("Bạn có muốn đọc dữ liệu từ file này? (y/n): ").strip().lower()
                if read == 'y':
                    doc_tu_file_html(file_path)
            else:
                print(f"❌ Không tìm thấy file HTML cho SBD {sbd_check}")
        except:
            print("❌ SBD không hợp lệ")
        exit()
    
    # Xử lý đầu vào SBD
    danh_sach_sbd = []
    
    if not sbd_input:
        danh_sach_sbd = [96001013]
    elif '-' in sbd_input:
        # Xử lý khoảng
        try:
            parts = sbd_input.split('-')
            tu_sbd = int(parts[0].strip())
            den_sbd = int(parts[1].strip())
            danh_sach_sbd = list(range(tu_sbd, den_sbd + 1))
            print(f"✅ Tạo khoảng từ {tu_sbd} đến {den_sbd} ({len(danh_sach_sbd)} SBD)")
        except:
            print("❌ Sai định dạng khoảng! Dùng mặc định.")
            danh_sach_sbd = [96001013]
    else:
        # Xử lý danh sách
        try:
            danh_sach_sbd = [int(x.strip()) for x in sbd_input.split(',') if x.strip()]
        except:
            print("❌ Sai định dạng! Dùng mặc định.")
            danh_sach_sbd = [96001013]
    
    # Kiểm tra file HTML đã có cho từng SBD
    print("\n🔍 Kiểm tra file HTML đã có...")
    sbd_da_co = []
    sbd_chua_co = []
    
    for sbd in danh_sach_sbd:
        file_path, exists = kiem_tra_file_html_sbd(sbd)
        if exists:
            sbd_da_co.append((sbd, file_path))
        else:
            sbd_chua_co.append(sbd)
    
    if sbd_da_co:
        print(f"\n✅ Đã có file HTML cho {len(sbd_da_co)} SBD:")
        for sbd, file_path in sbd_da_co:
            print(f"   • SBD {sbd}: {file_path}")
    
    if sbd_chua_co:
        print(f"\n⚠️ Chưa có file HTML cho {len(sbd_chua_co)} SBD: {sbd_chua_co}")
    
    # Hỏi người dùng có muốn đọc từ file HTML không
    if sbd_da_co:
        use_existing = input("\n📂 Bạn có muốn đọc dữ liệu từ file HTML đã có? (y/n): ").strip().lower()
        if use_existing != 'y':
            print("⚠️ Bỏ qua file HTML đã có, tiến hành crawl lại...")
            sbd_chua_co = danh_sach_sbd  # Crawl lại tất cả
            sbd_da_co = []
    
    # Giới hạn số lượng crawl mới
    if len(sbd_chua_co) > 20:
        print(f"\n⚠️ Bạn đang crawl {len(sbd_chua_co)} SBD mới. Có thể mất nhiều thời gian.")
        confirm = input("Bạn có chắc muốn tiếp tục? (y/n): ").strip().lower()
        if confirm != 'y':
            print("❌ Đã hủy")
            exit()
    
    # Xác nhận crawl
    if sbd_chua_co:
        print(f"\n📌 SBD cần crawl: {sbd_chua_co}")
        confirm = input("\n🔄 Bắt đầu crawl? (y/n): ").strip().lower()
        if confirm != 'y':
            print("❌ Đã hủy crawl")
            # Vẫn xử lý các file đã có
            if not sbd_da_co:
                exit()
    
    start_time = time.time()
    ket_qua_tong_hop = []
    
    # 1. Xử lý các SBD đã có file HTML
    for sbd, file_path in sbd_da_co:
        print(f"\n{'='*60}")
        print(f"📌 Đọc từ file HTML cho SBD {sbd}")
        print("="*60)
        
        ket_qua, thanh_cong = doc_diem_tu_file_html(file_path)
        
        ket_qua_tong_hop.append({
            'SBD': sbd,
            'Thanh_cong': thanh_cong,
            'Ket_qua': ket_qua,
            'File_html': file_path,
            'Tu_file': True
        })
    
    # 2. Crawl các SBD chưa có file
    for i, sbd in enumerate(sbd_chua_co, 1):
        print(f"\n{'='*60}")
        print(f"📌 Đang crawl {i}/{len(sbd_chua_co)}")
        print("="*60)
        
        ket_qua, file_html, thanh_cong, tu_file = tra_cuu_diem(sbd, max_retries=5, check_html_first=False)
        
        ket_qua_tong_hop.append({
            'SBD': sbd,
            'Thanh_cong': thanh_cong,
            'Ket_qua': ket_qua,
            'File_html': file_html,
            'Tu_file': tu_file
        })
        
        if i < len(sbd_chua_co):
            wait_time = random.uniform(3, 5)
            print(f"\n⏳ Chờ {wait_time:.1f} giây trước khi sang SBD tiếp theo...")
            time.sleep(wait_time)
    
    end_time = time.time()
    
    # Hiển thị tổng kết
    print("\n" + "="*60)
    print("📊 TỔNG KẾT KẾT QUẢ")
    print("="*60)
    
    thanh_cong = sum(1 for k in ket_qua_tong_hop if k['Thanh_cong'])
    tu_file = sum(1 for k in ket_qua_tong_hop if k.get('Tu_file', False))
    print(f"✅ Thành công: {thanh_cong}/{len(ket_qua_tong_hop)}")
    print(f"📂 Từ file HTML: {tu_file}")
    print(f"🌐 Từ web: {thanh_cong - tu_file}")
    print(f"❌ Thất bại: {len(ket_qua_tong_hop) - thanh_cong}/{len(ket_qua_tong_hop)}")
    print(f"⏱️  Tổng thời gian: {end_time - start_time:.2f} giây")
    
    print("\n📋 CHI TIẾT:")
    for k in ket_qua_tong_hop:
        status = "✅" if k['Thanh_cong'] else "❌"
        nguon = "📂 File" if k.get('Tu_file', False) else "🌐 Web"
        print(f"\n{status} SBD {k['SBD']} ({nguon})")
        if k['Thanh_cong'] and k['Ket_qua']:
            for mon, info in k['Ket_qua'].items():
                print(f"   • {mon}: {info['diem']} (data-score: {info['data_score']})")
        else:
            print(f"   ⚠️ Không tìm thấy điểm")
    
    # Xuất Excel
    data_rows = []
    for item in ket_qua_tong_hop:
        row = {
            'SBD': item['SBD'],
            'Nguon': 'File HTML' if item.get('Tu_file', False) else 'Web Crawl'
        }
        if item['Thanh_cong'] and item['Ket_qua']:
            for mon, info in item['Ket_qua'].items():
                row[mon] = info['diem']
            row['Trang_thai'] = 'Thành công'
        else:
            row['Trang_thai'] = 'Không tìm thấy'
        data_rows.append(row)
    
    df = pd.DataFrame(data_rows)
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    ten_file = f'ket_qua_diem_thi_{timestamp}.xlsx'
    df.to_excel(ten_file, index=False)
    print(f"\n💾 Đã xuất file Excel: {ten_file}")
    
    print("\n✅ HOÀN THÀNH!")