# 计算机网络

## 阻塞与非阻塞IO《C++新经典》

阻塞与非阻塞是什么意思？
阻塞和非阻塞主要是对调用一个系统功能函数时，该函数是否会导致进程进入sleep（睡眠）状态而言的。

- 1、阻塞IO

阻塞，就是调用一个函数，该函数就卡在这里，整个程序流程就不往下走了，此时程序进入休眠状态。
该函数卡在这里等待一个事件发生，只有这个事件发生了，该函数才会继续往下走，进程才会继续执行。

这种函数就是阻塞函数，如服务端使用的accept函数，调用其时，程序执行流就卡在accept这里，等待客户端连接，只有客户端连接，三次握手成功，accept才会返回。

这种阻塞效率低，每个进程应尽量把操作系统为其分配的时间片用完。而进程阻塞，操作系统就会立即把cpu从当前进程切换到另一个进程去，当前进程把属于自己的时间片拱手让人
所以优质程序一般不用阻塞方式

需要注意的是，accept函数可以阻塞，也可以不阻塞，主要取决于调用accept所提供的第一个参数，即监听套接字。
套接字在调用socket函数时创建，默认情况套接字都是阻塞的，用一个阻塞的套接字调用accept函数，accept函数就变成阻塞的函数了。

- 2、非阻塞IO

如果把监听套接字设置为非阻塞，那么调用accept时，就算没有客户端连接，accept函数也不会卡住，会立即返回（当然返回时有一个错误码，程序员通过错误码就能判断accept函数返回的原因）。
这样就能充分利用操作系统给进程分配的时间片来做别的事，执行效率更高。

## 异步与同步IO

- 1、异步IO

调用一个异步IO函数接收数据时，不管有没有数据，该函数都会立即返回。
程序员需要在调用异步IO函数时指定一个接收数据的缓冲区，还要指定一个回调函数，其它事情由操作系统去做，程序可以自由地干其他事。

- 2、同步IO

系统函数select和poll用的就是同步IO，本书重点的epoll，也可以划分为同步IO。

select函数在应用时，
首先调用select函数，判断是否有数据（只能判断是否有数据，并不能去取数据），如果没有数据就卡在那等；如果有数据，select函数返回，之后调用recvfrom函数去取数据。取数据时涉及到数据从内核空间复制到用户空间，所以复制数据时还要卡着。

所以，同步IO更麻烦，需要调用2个函数才能取到数据，其优点就是得到了IO复用的能力。

IO复用，就是多个socket（TCP连接）可以绑在一起，select的能力就是等多条TCP连接上的任意一条有数据到来，然后程序员再使用具体函数（如recvfrom）去收。

这种调用１个函数就能判断一批TCP连接是否有数据收到的能力，就叫IO复用，全称IO多路复用。

## epoll
 
IO多路复用用于监控多个TCP连接上的数据收发，而epoll就是一种在Linux上使用的IO多路复用并支持高并发的典型技术。
