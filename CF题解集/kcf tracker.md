 

中心误差 (Center location error): 每一帧中跟踪器输出的矩形框中心与实际中心位置的欧氏距 离. 加和后取平均值为平均中心误差. 中心误差越小, 说明跟踪效果越好

若中心误差小于一定阈值或重叠率大于一定阈值则认为该帧跟踪成功

精度图 (Precision plot) 与成功图 (Success plot): 将 3) 中所设置的阈值在一定范围内变动时, 会得到一系列的成功率数值所构成的曲线图, 当对应于中心误差时构成的曲线称为精度图; 对应于重 叠率时称为成功图.

![image-20200217210805913](C:\Users\樊世雄\AppData\Roaming\Typora\typora-user-images\image-20200217210805913.png)

跟踪准确率：

单个：

![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/image-20200216125723959.png)



全部：

![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/K8XMD%7E%5BT%25_T%24%7ESQ%7D71O%25%25MQ.png)



重叠率 (Overlap rate): 设 $ST$ 是跟踪器输出的跟踪框区域, $SG$ 为实际目标区域, 则重叠率的定义为两者的交集与并集的比值, 即:

​								$R=\frac{area(ST∩SG)}{area(ST∪SG)}$

重叠率越高, 说明跟踪效果越好.

![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/12.jpg)





![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/result.jpg)

成功率 (Success rate): 对于每一帧而言, 若中心误差小于一定阈值或重叠率大于一定阈值则认为该帧检测成功. 检测成功的帧数同视频序列总帧数的比值称为成功率.

​			![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/image-20200217121715777.png)

![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/image-20200217124608804.png)

![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/image-20200217205808872.png)





$Recall = \frac{TP}{(TP+FN)}=\frac{TP}{P}$



|        |       | Detect  |         |        |
| ------ | ----- | ------- | ------- | ------ |
| ground |       | Yes     | NO      | Total  |
| truth  | Yes   | TP(332) | FN(115) | P(447) |
|        | NO    | FP(90)  | TN(216) | N(306) |
|        | Total | P'(422) | N'(331) | 753    |

$ recall = \frac{332} { 447} = 74.3 \% $