import requests
from bs4 import BeautifulSoup

def search_google_scholar(keyword):
    url = f"https://scholar.google.com/scholar?hl=en&as_sdt=0%2C5&q={keyword}"
    
    # 发起GET请求并获取页面内容
    response = requests.get(url)
    html_content = response.text
    
    # 使用BeautifulSoup解析HTML内容
    soup = BeautifulSoup(html_content, "html.parser")
    
    # 查找所有的搜索结果元素
    results = soup.find_all("div", class_="gs_r gs_or gs_scl")
    
    # 提取搜索结果的标题和链接
    for result in results:
        title = result.find("h3", class_="gs_rt").text
        link = result.find("a")["href"]
        print(f"Title: {title}")
        print(f"Link: {link}")
        print("----------------------------------------------")

# 指定关键词进行搜索
keyword = "matesurface"
search_google_scholar(keyword)