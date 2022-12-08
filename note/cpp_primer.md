# 函数
- 每个cpp程序必须包含一个或者多个函数，其中一个必须命令为 ***main***
## 函数的组成
- 返回类型
- 函数名
- 形参列表
- 函数体
# 带符号类型与无符号类型
- 整型可以划分为
> - 带符号的signed(正数, 负数, 0)
> - 无符号的unsigned(大于0的值)

- 字符型分为
> - char
> - signed char
> - unsigned char ()

# 变量定义
- 变量定义的基本形式
> 类型说明符 + 变量名称

- 初始化
> - 列表初始化
>> - int sold = 0;
>> - int sold = {0};
>> - int sold{0};
>> - int sold(0);
> - 默认初始化
>> - string empty;

# 复合类型
- 引用
> int ival = m1024;
> 
> int &refVal = ival;
> 
> *引用必须初始化*
- 指针
> - 指针本身就是一个对象，允许对指针赋值和拷贝，可以先后指向几个不同的对象。
> - 指针无需在定义时赋初始值[没有被初始化也将用拥有一个不确定的值];  
> int *ip1, *ip2; 

map 和 vector 初始化的区别
- 定义vector
> vector<int> spec;  // 空vector，不含任何元素;
> vector<int> spec(10) // spec有10个元素，每个值都是0;

