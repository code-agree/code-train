import os
import openai
#填入你的OPENAI_API_KEY
openai.api_key = "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"

#代理设置：如果你在墙内需要使用代理才能调用，支持http代理和socks代理
#openai.proxy = "http://127.0.0.1:1080"

conversation=[{"role": "system", "content": "You are a helpful assistant."}]

while(True):
    user_input = input()      
    conversation.append({"role": "user", "content": user_input})

    response = openai.ChatCompletion.create(
        engine="gpt-3.5-turbo", # 模型.
        messages = conversation
    )

    conversation.append({"role": "assistant", "content": response['choices'][0]['message']['content']})
    print("\n" + response['choices'][0]['message']['content'] + "\n")