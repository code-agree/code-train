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

    # 创建一个用来保存文章信息的列表
    articles = []

    # 提取搜索结果的作者、作者单位和摘要
    for result in results:
        title = result.find("h3", class_="gs_rt").text
        link = result.find("a")["href"]
        author_elem = result.find("div", class_="gs_a")
        print(author_elem)  # 打印包含作者信息的div元素
        if author_elem:
            author_text = author_elem.get_text(separator=" - ").strip()
            author, affiliation = map(str.strip, author_text.split(" - ", 1))
        else:
            author = ""
            affiliation = ""

        # 提取摘要信息
        abstract_elem = result.find("div", class_="gs_rs")
        abstract = abstract_elem.text.strip() if abstract_elem else ""
        
        # 将文章信息添加到列表中
        articles.append({"作者": author, "作者单位": affiliation, "文章名称": title, "摘要": abstract})

    # 将文章信息输出到文本文件中
    with open("搜索结果.txt", "w", encoding="utf-8") as file:
        for article in articles:
            file.write(f"{article['作者']}-{article['作者单位']}-{article['文章名称']}-{article['摘要']}\n")
    # 将文章信息输出到文本文件中
    with open("output.txt", "w", encoding="utf-8") as file:
        for article in articles:
            file.write(f"{article['作者']}-{article['作者单位']}-{article['文章名称']}-{article['摘要']}\n")
# 指定关键词进行搜索
keyword = "metasurface"
search_google_scholar(keyword)