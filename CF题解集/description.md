

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/Figure_1.png">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">图二：横坐指值区域重叠率，纵坐标指该区域重叠率占比。</div>
</center>

​	 **实验过程：**对于目标检测，我们使用我们自己的数据集七百多帧图片进行了准确度测试。设置每一帧与第一针的对比来查看是否有目标创新（目标检测描述）。我们通过计算每一帧的检测值与真实值的区域重叠率(IOU)并且每一段区域重叠率在所有的测试集中所占的比例来表示我们的算法的准确度。我们设置了阈值$θ$，来代表区域重叠率大于$θ$ 的检测值是正常的。通过计算正常的帧占总测试帧数的比例得到了目标检测算法精度。

​	**实验结果:**图2显示了我们的检测算法在所有测试集上的结果。图中$(0， 0.110)$处可能是我们的测试值与真实值有些误差导致的。除此之外，我们的算法取得了比较满意的结果：区域重叠率大于$50\%$的帧有$69\%$。

