import asyncio

# async：声明这是一个“可以暂停”的函数（协程）
async def boil_water():
    print("开始烧水...")
    await asyncio.sleep(5)  # await：挂起当前任务，去干别的
    print("水烧好了！")

async def order_food():
    print("下单外卖...")
    await asyncio.sleep(30)  # 模拟等外卖
    print("外卖到了！")

async def write_email():
    print("开始写邮件...")
    await asyncio.sleep(10)
    print("邮件发送成功！")

# 主函数：协调所有任务
async def main():
    # 创建任务列表
    tasks = [
        asyncio.create_task(boil_water()),
        asyncio.create_task(order_food()),
        asyncio.create_task(write_email())
    ]
    # 等待所有任务完成
    await asyncio.gather(*tasks)

# 启动异步事件循环
asyncio.run(main())