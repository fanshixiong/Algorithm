## MOTS：多目标跟踪和分割论文翻译

#### 摘要：

   		本文将目前流行的多目标跟踪技术扩展到多目标跟踪与分割技术(MOTS)。为了实现这个目标，我们使用半自动化的标注为两个现有的跟踪数据集创建了密集的像素级标注。我们的新标注包含了10870个视频帧中977个不同对象(汽车和行人)的65,213个像素掩膜。为了进行评估，我们将现有的多目标跟踪指标扩展到这个任务。同时，我们还提出了一种新的基线方法，该方法通过单个神经网络解决检测，跟踪和分割问题。我们通过在MOTS标注(MOTS annotations)上面训练时实现性能的改进来展示我们数据集的价值。我们相信，我们的数据集，指标和基线将成为开发超出2D边界框的多目标跟踪方法的宝贵资源。我们在下面的网站上提供了注释，代码和模型：[MOTS](https: //www.vision.rwth-aachen.de/page/mots)

---

#### 一、介绍：	

​		近年来，计算机视觉领域在日益艰难的任务中取得了显著进步。深度学习技术现在在对象检测以及图像和实例分割中具有很好(impressive)的表现。但是，跟踪仍然具有挑战性，尤其是涉及多个对象时。 特别是最近的跟踪评估结果表明边界级跟踪性能已经达到饱和，只有在移动到像素级别时才能进一步改进。因此，我们建议将所有的三个任务---视为需要一起考虑的相互关联的问题。

​		用于训练和评估目标分割模型的数据集通常不提供关于视频数据的标注，甚至不提供关于不同图像中对象身份的信息。另一方面，多目标跟踪的常用数据集仅提供对象的边界框注释。这些可能太过于粗糙。例如：当目标被部分遮挡时，其边界框包含来自其他目标而不是自身的信息(参见图1)。在这种情况下，像素级的目标分割可以得到更加自然的场景描述，并为后续的处理提供额外的信息。对于分割掩膜，有一个定义好的ground truth，而许多不同(non-tight)的框可能大致适合一个对象。类似地，与通常需要在评估时通过启发式匹配过程解决的ground truth相比，带有重叠边界框的跟踪会产生歧义。另一方面，根据定义，基于分割的跟踪结果是不重叠的，因此可以直接与ground truth进行比较。

<center>    <img style="border-radius: 0.3125em;    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);"     src="https://pic3.zhimg.com/80/v2-8d14addcdd01ce9ebc7e76c8c6c09206_hd.jpg">    <br>    <div style="color:orange; border-bottom: 1px solid #d9d9d9;    display: inline-block;    color: #999;    padding: 2px;">图一：分割vs边界框。当对象相互经过时，该对象的边界框的很大一部分可能属于另一个对象，而逐像素分割掩膜则精确定位目标。上图显示来自KITTI MOTS数据集。</div> </center>

​		因此，本文提出将多目标跟踪任务扩展到实例分割跟踪。我们称这个新任务为“多目标跟踪和分割(MOTS)”。就我们所知，到目前为止还没有这个任务的数据集。虽然文献中有许多方法来用于边界框跟踪，但MOTS需要结合时间和掩码提示才能成功。因此，我们提出TrackR-CNN作为解决MOTS任务的所有方面的基线方法。TrackR-CNN利用3D卷积扩展Mask R-CNN 以结合时间信息，并通过关联头随时间链接对象身份。

​		综上所述，本文做出如下贡献：(1) 基于流行的KITTI和MOTChallenge数据集，我们为解决MOTS任务的训练和评估方法提供了两个具有时间一致性对象实例分割的新数据集。(2) 我们提出了一种新的软多目标跟踪和分割准确度(sMOTSA)测量方法，可以同时对新任务的各个方面进行评估。(3) 我们提出了TrackR-CNN作为一种解决检测、跟踪和分割问题的基线方法，并将其与现有的工作进行了比较。(4) 我们证明了新数据集在像素级多对象跟踪器的端到端训练中的有用性。特别是，我们的数据集表明了分割和跟踪程序的联合训练变得可能，并且在例如分割或边界框跟踪方面产生改进，这在以前是可能的。



---

#### 二、相关工作

​		**多目标跟踪数据集：** 在多目标跟踪（MOT）任务中，必须将来自已知类集的最初未知数量的目标作为视频中的边界框来跟踪。特别是目标可以随时进入和离开场景，并且必须经过长时间的遮挡和外观变化才能恢复。许多MOT数据集专注于街景，例如KITTI跟踪数据集，其中包含来自车载摄像头的视频；MOTChallenge数据集显示了来自各种不同视角的行人。UA-DETRAC也有街景，但仅包含车辆标注。另一个MOT数据集是PathTrack，它提供了不同场景中人体轨迹的标注。PoseTrack包含视频中多人的关节位置标注。这些数据集都没有为带注释的对象提供分割掩码，因此无法充分详细地描述图1中所示的复杂交互。

​		**视频目标分割数据集：**在视频目标分割（VOS）任务中，在视频的第一帧中提供一个或多个通用目标的实例分割，并且必须在所有后续帧中以像素精度进行分割。现有的VOS数据集仅包含很少的对象，这些对象也存在于大多数帧中。此外，此任务的常见评估指标（区域Jaccard索引和边界F-measure）不会将跟踪多个对象时可能出现的ID变换等错误情况考虑在内。相比之下，MOTS专注于一组预先定义的类别，并考虑具有许多交互对象的拥挤场景。MOTS还增加了发现和跟踪在场景中出现和消失的不同数量的新对象的难度。

​		VOS任务的数据集包括DAVIS 2016数据集，它专注于单对象VOS，以及DAVIS 2017 数据集，它扩展了多对象VOS的任务。 并且YouTube-VOS数据集同样可用，并且比DAVIS大几个数量级。 此外，Segtrackv2 数据集，FBMS 和YouTube对象数据集的带注释子集都可用于评估此任务。

​		**视频实例分割数据集。**Cityscapes，BDD和ApolloScape为汽车场景提供视频数据。 然而，实例标注仅针对非相邻帧的一小部分提供，或者在ApolloScape的情况下，针对每个帧提供，但不随时间推移提供对象身份。 因此，它们不能用于像素级跟踪方法的端到端训练。

​		**方法。**虽然对MOT或VOS任务提出的方法的全面回顾超出了本文的范围，但我们将回顾已经解决MOTS任务（子集）或与在其他方面与TrackR-CNN相关的一些工作。

​		Seguin等人使用超像素级别的聚类从给定的边界框轨迹导出实例分割，但它们不解决检测或跟踪问题。米兰等人考虑利用超像素信息和给定对象检测在CRF中联合跟踪和分割。与这两种方法相反，我们提出的基线在像素而非超像素级别上运行。 CAMOT 使用立体信息对KITTI数据集上的通用对象进行基于掩模的跟踪，这限制了其对远距离对象的准确性。CDTS 执行无监督的VOS，即不使用第一帧信息。它仅考虑具有少量对象外观和消失的短视频剪辑。然而，在MOTS中，许多物体经常进入或离开拥挤的场景。虽然上述方法能够使用分割掩模生成跟踪输出，但由于不存在具有MOTS标注的数据集，因此无法全面评估其性能。

​		Lu等人通过聚合每帧的位置和外观特征并使用LSTM跨时间组合来实现跟踪。 Sadeghian等人还使用LSTM的组合将通过裁剪检测获得的外观特征与速度和交互信息组合。 在这两种情况下，组合的特征都输入到传统的匈牙利匹配程序中。 对于我们的基线模型，我们直接使用时间信息直接丰富检测，并与检测器一起学习关联特征，而不仅仅是给定检测进行“后处理”。

​		**半自动注释。**存在许多用于半自动实例分割的方法，例如， 从涂鸦或点击生成分割掩模。 这些方法需要用户输入每个要分割的对象，而我们的注释过程可以完全自动地分割许多对象，让注释器专注于改善不同情况的结果。 虽然这有点类似于主动学习设置，但我们将使用人工注释器来决定注释哪些对象，以保证所有注释都达到长期基准数据集所需的质量。

​		其他半自动注释技术包括Polygon-RNN，它自动预测多边形形式的分割，顶点可以由注释器校正。Fluid Annotation允许注释器操作Mask RCNN预测的片段，以便注释完整的图像。虽然加快了在隔离帧中对象的分割掩码的创建，但这些方法并不在跟踪级别上操作，也不使用现有的边界框注释，也不利用在其他视频帧中为相同对象注释的分割掩码。



-----

#### 三、数据集

​		为视频中每个对象的每个帧注释像素掩模是一项非常耗时的任务。 因此，这种数据的可用性非常有限。 我们不知道MOTS任务的任何现有数据集。 但是，有一些带有MOT标注的数据集，即在边界框级别标注的轨迹。 对于MOTS任务，这些数据集缺少分割掩模。 因此，我们的注释过程为两个MOT数据集中的边界框添加了分割掩模。 总共，我们注释了65,213个分割掩模。 这种规模使我们的数据集在训练和评估基于学习的技术方面是可行的。

​		**半自动标注程序。**为了使标注工作易于管理，我们提出了一种半自动方法，通过分割掩模扩展边界框级别标注。 我们使用卷积网络从边界框自动生成分割掩膜，然后使用手动多边形标注进行校正步骤。 每条轨迹，我们使用手动标注作为附加训练数据来调整初始网络，类似于[6]。 我们迭代生成和校正掩模的过程，直到达到所有注释掩模的像素级精度。

​		为了将边界框转换为分割掩模，我们使用基于DeepLabv3+的完全卷积改进网络，该网络将边界框指定的输入图像作为输入，并添加了一个小的上下文区域，以及附加输入通道，将边界框编码为掩模。 在此基础上，细分网络预测给定框的分割掩码。 改进的网络在COCO 和Mapillary 上进行了预训练，然后针对目标数据集进行了手动创建的分割掩模的训练。

​		在开始时，我们为所考虑的数据集中的每个对象注释(作为多边形)两个分割掩膜。网络首先在所有手动创建的掩码上进行训练，然后针对每个对象分别进行微调。然后使用这些网络的微调变量来为数据集中各个对象的所有边界框生成分割掩膜。这样，网络就适应了每个对象的外观。对于每个对象使用两个手工标注的分割掩码进行微调，改进的网络已经为其他帧中对象的外观生成了相对良好的掩膜，但通常仍然存在小错误。因此，我们最终会纠正一些有缺陷的生成掩膜，并在迭代过程中重新运行训练过程。我们的标注器还纠正了原始MOT数据集中的不精确或错误的边框标注。

​		**KITTI MOTS。**我们在KITTI跟踪数据集的边界框级别注释上执行了上述标注过程。 标注的样本如图2所示。为了便于训练和评估，我们将KITTI跟踪数据集2的21个训练序列分别划分为训练和验证集3。 我们的分配平衡了每个类别的出现次数—汽车和行人—在训练和验证集中大致相等。 统计数字见表1。



<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://pic2.zhimg.com/80/v2-36fc36d81060014a8b647d10730d7b89_hd.jpg">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">图 2：我们标注的样例图片。KITTIMOTS(上)和MOTSChallenge(下)</div>
</center>





<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://pic4.zhimg.com/80/v2-ac3809ac8ee9fb8a99ab725c5406ef9b_hd.jpg">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">表 1：引入的KITTI MOTS和MOTSChallenge数据集的统计数据。我们考虑行人的数据集和汽车的KITTI MOTS。</div>
</center>



​		需要相对较多的手动标注表明现有的单图像实例分割技术在此任务上仍然表现不佳。 这是我们提出的MOTS数据集的主要动机，其允许将时间推理结合到实例分割模型中。

​		**MOTSChallenge。**我们进一步标注了MOTChallenge 2017 训练数据集4的7个序列中的4个，并获得了MOTSChallenge数据集。 MOTSChallenge专注于拥挤场景中的行人，并且由于许多遮挡情况而非常具有挑战性，因为像素方面的描述尤其有益。 标注的样本如图2所示，统计数据在表1中给出。



----

#### 四、评价准则

​		作为评估措施，我们将完善的CLEAR MOT指标用于多目标跟踪以适应我们的任务。 对于MOTS任务，需要在评估度量中容纳每个对象的分割掩模。 受Panoptic Segmentation任务的启发，我们要求对象的ground truth掩模和MOTS方法产生的掩模都不重叠，即每个像素最多可分配给一个对象。 我们现在介绍我们对MOTS的评估措施。

​		形式上，具有$T$个时间帧，高度$h$和宽度$w$的视频的ground truth由一组$N$个非空的ground truth像素掩模 ![[公式]](https://www.zhihu.com/equation?tex=M+%3D+%5Cleft%5C%7B+m_%7B1%7D%2C+...%2C+m_%7BN%7D+%5Cright%5C%7D) 组成，其中 ![[公式]](https://www.zhihu.com/equation?tex=m_%7Bi%7D+%5Cin+%5Cleft%5C%7B+0%2C1+%5Cright%5C%7D%5E%7Bh%5Ctimes+w%7D) ，每个属于相应的时间帧 ![[公式]](https://www.zhihu.com/equation?tex=t_%7Bm%7D+%3D+%5Cleft%5C%7B+1%2C+...%2C+T+%5Cright%5C%7D) 并被赋予ground truth 跟踪id ![[公式]](https://www.zhihu.com/equation?tex=id_%7Bm%7D+%5Cin+%5Ctextbf%7BN%7D) 。MOTS方法的输出是一组$K$非空假设掩模 ![[公式]](https://www.zhihu.com/equation?tex=h+%3D+%5Cleft%5C%7B+h_%7B1%7D%2C...%2Ch_%7BK%7D+%5Cright%5C%7D) ，其中 ![[公式]](https://www.zhihu.com/equation?tex=h_%7Bi%7D+%5Cin+%5Cleft%5C%7B+0%2C1+%5Cright%5C%7D%5E%7Bh%5Ctimes+w%7D) ，每个都被赋予一个假设的轨迹id ![[公式]](https://www.zhihu.com/equation?tex=id_%7Bh%7D+%5Cin+%5Ctextbf%7BN%7D) 和一个时间帧 ![[公式]](https://www.zhihu.com/equation?tex=t_%7Bh%7D+%3D+%5Cleft%5C%7B+1%2C+...%2C+T+%5Cright%5C%7D) 。

​		**建立对应关系。**CLEAR MOT指标的一个重要步骤是建立ground truth对象和跟踪器假设之间的对应关系。 在基于边界框的设置中，建立对应关系是非平凡的并且通过二分匹配来执行，因为ground truth框可以重叠并且多个假设框可以很好地适应给定的ground truth框。 在MOTS的情况下，由于我们要求每个像素在ground truth和假设中都是唯一的，所以建立对应大大简化了。 因此，对于给定的ground truth掩模，至多一个预测掩模可以具有大于0.5的交叉联合（IoU)。 因此，从假设掩模到ground truth掩模的映射 ![[公式]](https://www.zhihu.com/equation?tex=c%3AH%5Crightarrow+M+%5Ccup%5Cleft%5C%7B+%5Coslash+%5Cright%5C%7D) 可以简单地使用基于掩模的IoU定义为

![img](https://pic3.zhimg.com/80/v2-6be966e931e00606d8644251c45c09e6_hd.jpg)

​		True positives的集合 ![[公式]](https://www.zhihu.com/equation?tex=TP+%3D+%5Cleft%5C%7B+h%5Cin+H+%7C+c%28h%29+%5Cne+%5Coslash+%5Cright%5C%7D) 由映射到ground truth掩模的假设掩模组成。 类似地，false positives是未映射到ground truth掩模的假设掩模，即 ![[公式]](https://www.zhihu.com/equation?tex=FP+%3D+%5Cleft%5C%7B+h%5Cin+H+%7C+c%28h%29+%3D+%5Coslash+%5Cright%5C%7D) 。 最后，false negatives的集合 ![[公式]](https://www.zhihu.com/equation?tex=FN+%3D+%5Cleft%5C%7B+m%5Cin+M+%7C+c%5E%7B-1%7D%5Cleft%28+m+%5Cright%29+%5Cne+%5Coslash+%5Cright%5C%7D) 包含未被任何假设掩模覆盖的ground truth掩模。

​		在下文中，让 ![[公式]](https://www.zhihu.com/equation?tex=pred%3A+M%5Crightarrow+M%5Ccup%5Cleft%5C%7B+%5Coslash+%5Cright%5C%7D) 表示最近跟踪的ground truth掩模的前一个(predecessor)，或者如果没有跟踪的前一个存在则∅。 所以 ![[公式]](https://www.zhihu.com/equation?tex=q%3Dpred%28p%29) 是具有相同 $id(id_q-id_p)$ 的掩模q和使得 ![[公式]](https://www.zhihu.com/equation?tex=c%5E%7B-1%7D%5Cleft%28+q+%5Cright%29%5Cne+%5Coslash) 的最大 $t_q < t_p$ 。然后将id转换的集合IDS定义为 一系列ground truth掩模，其前一个被跟踪不同的身份。形式上，

![img](https://pic4.zhimg.com/80/v2-e3e142b48e2cb8eb8c999ccbb4785657_hd.jpg)

​		**基于掩模的评估措施。**另外，我们 通过

![img](https://pic3.zhimg.com/80/v2-073e72b63bdf0016b47a8f72c175b1c6_hd.jpg)

定义了true positives数量的soft ![[公式]](https://www.zhihu.com/equation?tex=%5Ctilde%7BTP%7D) 。

鉴于之前的定义，我们定义了原始CLEAR MOT指标的基于掩模的变体。 我们提出多对象跟踪和分割准确度（MOTSA）作为基于框的MOTA度量的基于掩模IoU的版本，即

![img](https://pic3.zhimg.com/80/v2-494a7e0cb794820bef0097836bbb215a_hd.jpg)

并且基于掩模的多目标跟踪和分割精度（MOTSP）为

![img](https://pic2.zhimg.com/80/v2-f4ef6eec3b232225a292343db3364155_hd.jpg)

最后，我们介绍了soft多目标跟踪和分割精度（sMOTSA）

![img](https://pic4.zhimg.com/80/v2-5d8c68cd313b181b2dee118fae55f907_hd.jpg)

它累积了 true positives 的soft number ![[公式]](https://www.zhihu.com/equation?tex=%5Ctilde%7BTP%7D) ，而不是计算有多少掩模达到超过0.5的IoU。因此，sMOTSA可以衡量分割以及检测和跟踪质量。



-----

#### 五、方法

​		为了解决检测，跟踪和分割，即MOTS任务，与神经网络联合，我们建立在流行的Mask R-CNN 架构上，该架构通过掩模head扩展了Faster R-CNN检测器。 我们提出TrackR-CNN（参见图3），其又通过一个关联头（association head）和两个3D卷积层来扩展Mask R-CNN，以便能够随时间关联检测并处理时间动态。 TrackR-CNN提供基于掩模的检测以及关联特性。 两者都输入到跟踪算法，该算法决定选择哪些检测以及如何随时间链接它们。

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://pic3.zhimg.com/80/v2-4b81e59cc2505e40b3abb9a6fd6c9e4a_hd.jpg">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">图 三: TrackR-CNN概述。我们通过3D卷积扩展Mask R-CNN以结合时间上下文和通过为每次检测产生关联向量的关联头。关联向量之间的欧几里德距离用于将检测随时间关联到轨迹中。与Mask R-CNN的差异以黄色突出显示。</div>
</center>



​		**整合时间上下文。** 为了利用输入视频的临时上下文，我们将3D卷积（其中第三个维度是时间）整合到以ResNet-101为骨干网的Mask R-CNN中。 3D卷积应用于主干特征，以便增强主干特征得时序性。 然后，区域提议网络（RPN）将使用这些增强的特征。 作为替代方案，我们还考虑卷积LSTM 层。 卷积LSTM通过使用卷积而不是矩阵乘积计算其激活来保留输入的空间结构。

​		**Association Head（关联头）。**为了将检测随时间关联的数据，我们通过关联头扩展Mask R-CNN，该关联头是一个全连接层，其将区域提议作为输入并且预测每个提议的关联向量。 关联头的灵感来自用于人体重新识别的嵌入向量。 每个关联向量表示汽车或人的身份。它们的训练方式是属于同一实例的向量彼此接近，属于不同实例的向量彼此相距遥远。 我们将两个关联向量v和w之间的距离 $d(v, w)$ 定义为它们的欧几里德距离，即

![img](https://pic3.zhimg.com/80/v2-a169d8934963c7618e8f065b5b87aa5a_hd.jpg)

​		我们使用Hermans等人提出的batch hard triplet loss 来训练关联头适用于视频序列。 这种损失对每次检测都会产生硬阳性（hard positives ）和硬阴性（hard negatives）。 正式地，让$D$表示视频的检测集。 每个检测 $d ∈D$ 由掩模 $mask_d$ 和关联矢量 $a_d$ 组成，其来自时间帧 $t_d$ ，并且被分配由其与ground truth对象的重叠确定的ground truth轨迹id $id_d$ 。 对于$T$时间步长的视频序列，具有边际$α$的batch-hard formulation中的关联损失由下式给出

![img](https://pic1.zhimg.com/80/v2-3411377996c8a8dc31d84f6db869537c_hd.jpg)

​		**Mask传播。** 基于掩模的$IoU$与光流扭曲（warping）一起是一种强有力的提示，用于随时间关联像素掩模。 因此，我们还尝试使用掩模扭曲作为关联向量相似性的替代提示。 对于在时间$t-1$处的检测$d∈D$具有掩模$mask_d$并且在时间$t$处具有掩模 $mask_e$ 的检测$e∈D$，我们定义掩模传播得分为

![img](https://pic1.zhimg.com/80/v2-e3efa74186a2e9987c2fcd7200f26af8_hd.jpg)

其中$W(m)$表示通过帧$t-1$和$t$之间的光流向前的扭曲掩模$m$。

​		**跟踪。** 为了产生最终结果，我们仍然需要决定报告哪些检测以及如何将它们随时间链接到轨迹中。 为此，我们将现有的基于关联向量相似度的轨迹检测扩展到该轨迹的最新检测。

​		更确切地说，对于每个类和每个帧$t$，我们将检测置信度大于阈值$γ$的当前帧的检测与之前帧中使用关联向量距离公式7选择的检测联系在一起。我们只选择最近的检测，直到过去的$β$帧阈值。 使用匈牙利算法进行匹配，同时仅允许距离小于阈值$δ$的成对检测。 最后，所有未分配的高置信度检测都会启动新的轨迹。

​		生成的轨道可以包含重叠的掩码，我们不允许执行MOTS任务（参见第4节）。 在这种情况下，属于具有较高置信度的检测的像素（由我们的网络的分类头部给出）优先于具有较低置信度的检测。



-----

#### 六、实验

​		**实验设置**。对于Mask R-CNN，我们使用一个ResNet-101主干，并在COCO和Mapillary上进行预训练。然后，我们通过添加关联头，将两个深度的3D卷积层与3×3×3滤波核(二维空间的，三维时间)、ReLU激活层以及1024个背骨与区域建议网络之间的特征映射进行集成，构建TrackR-CNN。将3D卷积初始化为一个标识函数，然后应用ReLU函数，在使用卷积LSTM时，在训练的初始步骤中，随机初始化权值，并在后续层的预训练权值的预服务激活中加入一个跳跃连接。然后，TrackR-CNN对目标数据集进行训练，即KITTI MOTS 或MOTSChallenge，使用Adam优化器，以$5*10^{-7}$的学习速度进行了40个循环的测试。在训练期间，使用由单个视频的8个相邻帧组成的小批量，其中8是使用Titan X (Pascal)graph-ics卡能够装入内存的最大帧数。在批处理边界处，3D卷积层的输入在时间上是零填充的。使用卷积LSTM时，梯度在训练过程中通过全部8帧反向传播，在测试时在整个序列上传播递归状态。关联头产生的向量有128个维度，公式8中定义的关联损失是在一批检测中计算出来的。我们选择的优势$α= 0.2$, 这被证明是有用的。对于掩模传播实验，我们使用PWC-Net来计算所有相邻帧对之间的光流。我们的整个跟踪器在测试时达到了大约每秒2帧的速度。当使用卷积LSTM时，它是在线运行的，当使用3D卷积时，由于两帧的关系，它是在3D卷积之前运行的。

​		我们每个实验的跟踪系统调优的阈值$(α, β, γ)$每一个类分别在目标训练集与随机搜索进行1000次迭代。

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://pic2.zhimg.com/80/v2-4eff15c57420f06cf54346679466c0d9_hd.jpg">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">表 2： KITTI MOTS上的结果。+ MG表示使用KITTI MOTS 微调 Mask R-CNN生成掩模。 BeyondPixels是一种先进的汽车MOT方法，使用与其他方法不同的检测器。</div>
</center>

​		**主要结果。** 表2显示了我们在KITTIMOTS验证集上的结果。我们取得了有竞争力的结果，击败了几个基准方法。Mask R-CNN + maskprop表示一个简单的基线，我们在KITTI MOTS训练集的框架上对COCO和Mapillary预训练Mask R-CNN进行了微调。然后我们在验证集上对其进行评估，并使用掩模传播评分(参见第5节)将基于掩模的检测随时间联系起来。与此基线相比，TrackR-CNN获得了更高的sMOTSA 和 MOTSA评分，这意味着3D卷积分层和关联头有助于识别视频中的对象。MOTSP得分也是一样的。

​		TrackR-CNN(box orig)表示我们的模型在KITTI的原始边界框注释上经过无掩模头部训练的一个版本。然后我们根据KITTI在我们的训练片段上的原始跟踪注释来调整MOTA的分数。在我们的MOTS设置中，我们通过添加分割掩膜(用+MG表示)和KITTI微调掩膜R-CNN的掩膜头部作为后处理步骤来评估这一基线。这种设置的sMOTSA和MOTSA得分比我们的方法和之前的基线更差，特别是考虑到行人时，此外，我们还观察到，非紧密边界框并不是跟踪的理想线索，而仅仅在边界框谓词上使用实例划分方法不足以解决MOTS任务。我们在图4中显示了这条基线的定性结果。基于边界框的模型经常混淆相似的闭塞对象，导致掩膜和身份开关丢失。相反，我们的模型假设了一致的掩模(marks)。

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://pic1.zhimg.com/80/v2-5bbf0276aee88406c29379ab543eb410_hd.jpg">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">图 4：KITTI MOTS上的定性结果。 (a) +(c): 我们的TrackR-CNN模型评估了KITTI MOTS的验证序列。(b)+(d): TrackR-CNN（box orig）+ MG在相同序列上的评估。在我们的数据上使用掩模进行训练可以避免类似的近距离物体之间的混淆。</div>
</center>

​		为了证明像上面那样添加分割掩膜不会带来(不)公平的优势，我们还使用了MASK R-CNN掩膜头来替换我们的方法生成的掩膜(TrackR-CNN (our) + MG)。结果大致相似，所以没有出现主要的(劣)优势。结合我们的基线实验，我们发现对于视频的时间一致性的实例分割数据的训练比没有时间信息的实例分割数据的训练和仅仅对边界框跟踪数据的训练都有优势。这两方面的联合训练在以前是不可能的，这强调了我们提出的MOTS数据集的有用性。

​		CAMOT是一个基于掩码的跟踪器，它可以跟踪来自预定义类的对象和使用来自KITTI中立体设置的3D信息的通用对象。在原始版本中，CAMOT将来自SharpMask的通用对象建议作为输入。为了具有更好的可比性，我们使用来自TrackR-CNN的检测(通过运行它作为一个正常的探测器，没有关联)作为输入。请注意，CAMOT只能跟踪立体的深度可用的区域，这限制了它的回调。结果表明，当使用相同的输入检测集时，我们提出的跟踪方法比传统的跟踪方法CAMOT有更好的性能。

​		由于基于掩码的跟踪器的源代码不多，我们也考虑了基于边界框的跟踪方法CIWT和BeyondPixels，并再次使用KITTI微调掩码R-CNN掩码头将其结果转换为分割掩码。注意，这些方法经过了调优，在最初的基于边界框的任务上表现良好。

​		CIWT将基于图像的信息与来自stereo的三维信息相结合，在图像和世界空间中进行联合跟踪。再次，从我们的TrackR-CNN的检测用于可比性。我们所提出的追踪系统在产生自适应的掩膜时，可同时处理追踪与掩膜的产生，其效能优于连续小波变换。

​		BeyondPixels是KITTI原始跟踪数据集中最强大的汽车跟踪方法之一。它结合了外观信息和3D线索。我们无法运行他们的方法与我们的检测，因为他们的代码提取外观特征是不可用的。相反，我们使用了从RRC获得的原始检测，RRC是一种非常强大的探测器。RRC特别在KITTI上实现了精确的定位，而更为传统的MASK R-CNN检测器设计用于一般的目标检测。最终得到的sMOTSA和MOTSA的分数比我们的方法要高，但仍然表明在MOTS上使用Mask R-CNN分割边界框时，最先进的边界框跟踪方法是有限制的。

​		**MOTS用Ground Truth边界框。**为了便于比较，我们基于边界框ground truth得到了分割结果，并在新的标注中对其进行了评估。在这里，我们考虑了ground truth的两个变体:来自KITTI (orig)的原始边界框，它们是模态，即如果只有一个人的上半身是可见的，边界框将仍然延伸到地面，另一种是紧密的边界框(tight)从我们的分割掩膜。同样，我们使用KITTI MOTS微调的MASK R-CNN生成掩膜。我们的研究结果表明，即使使用完美的轨迹假设，生成精确的掩模仍然具有挑战性，尤其是对行人而言。在使用模态框时更是如此，它通常包含不显示对象的较大区域。这进一步证实了我们的观点，MOT任务可以从像素级评估中获益。进一步的基准，我们用矩形或椭圆填充ground truth框可以在补充材料中找到。

​		**时间成分。**在表3中，我们比较了TrackR-CNN时间分量的不同变量。$1×Conv3D$和$2×Conv3D$表示在基干和区域建议网络之间使用一个或叠加两个深度可分的3D卷积层，每层有1024个维度。类似地，$1×Conv$和$2×ConvLSTM$表示在同一阶段有一个或两个堆叠的卷积LSTM层，每个层有128个特征通道。在卷积LSTM中，由于门的存在，每个特征通道的参数数更高。在最初的实验中，使用更多的特征通道似乎没有什么帮助。最后，不添加任何额外的层作为临时组件$(None)$。与基线相比，增加两个3D卷积层可以显著改善行人的sMOTSA和MOTSA分数，而对汽车的评分则可以进行类比。令人惊讶的是，使用卷积LSTM并没有比基线产生任何显著的效果。

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://pic1.zhimg.com/80/v2-bb92e3bba205a52fe64542f3b56818ec_hd.jpg">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">表 3：TrackR-CNN的不同时间成分在KITTI MOTS上的结果比较。(a)+(c)我们的TrackR-CNN模型对KITTI MOTS的验证序列进行了评估。(b)+(d) TrackR-CNN (box orig) + MG对同一序列进行评价。在我们的数据上使用蒙板进行训练，可以避免附近相似物体之间的混淆。</div>
</center>



​		**关联机制。**在表4中，我们比较了不同的检测关联机制。每一行都遵循第5节中介绍的建议的跟踪系统，但是匈牙利匹配步骤使用了不同的分数。当使用关联头，关联头向量可能对过去检测到$β$帧进行匹配。对于其余的关联机制，只有相邻帧之间的匹配才是合理的。



<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://pic4.zhimg.com/80/v2-678806206822b20cee16b8177e2f88a3_hd.jpg">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">表 4：TrackR-CNN的不同关联机制在KITTI MOTS上的结果比较。</div>
</center>

​		对于MASK IoU，我们只使用来自等式9的掩模传播分数，这会降低sMOTSA和MOTSA的分数。这强调了我们的关联头的有用性，它可以使用单个神经网络提供的嵌入来超越基于光流的提示。在这里，我们也尝试了没有关联头损失的训练$(MASK IoU(train w/oassoc.))$，这更降低了MOTSA的分数。因此，关联损耗对检测器本身也有积极的影响。令人惊讶的是，使用边界框IoU(其中边界框被框内的光流值的中间值扭曲，$Bbox\ IoU$)执行的效果几乎与mask IoU相同。最后，仅使用边界框中心(Bbox Center)的距离进行关联，即做最近邻搜索，会显著降低性能。

​		**MOTS挑战。**表5显示了我们在MOTSChallenge数据集上的结果。因为MOTSChallenge只有4个视频序列，所以我们将我们的方法(TrackR-CNN(ours))训练成一种忽略不计的方式(用一个训练过并调整了其他3个序列的模型来评估每个序列)。为了进行比较，我们使用四种在MOT17基准测试中表现良好的方法的预先计算结果，并使用在MOTSChallenge上经过调优的Mask R-CNN生成掩膜(以一种遗漏的方式)来评估我们的数据。我们注意到，所有四组结果都使用了SDP生成的最强公共检测集，而TrackR-CNN生成了自己的检测。同样不清楚的是，这些方法有多少被训练得在MOTChallenge训练集上表现良好。尽管存在这些可能性，但TrackR-CNN的表现优于其他所有方法。最后一行表明，即使随着时间的推移，包括跟踪信息在内的严格的ground truth边界框，准确分割所有行人仍然是困难的

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://pic3.zhimg.com/80/v2-e43a2e37ab21b31a97716dd5f2668f96_hd.jpg">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">表 5：MOTSChallenge上的结果。+ MG表示使用域fine-tuned的Mask R-CNN生成掩模。</div>
</center>



----

#### 七、结论

​		到目前为止，还没有用于评估多对象跟踪和分割的任务的基准或数据集，并且使用这种时间上一致的基于掩模的跟踪信息直接训练方法。 为了缓解这个问题，我们引入了两个基于现有MOT数据集的新数据集，我们使用半自动标注过程进行标注。 我们基于常用的MOTA指标进一步介绍了MOTSA和sMOTSA指标，但适用于评估基于掩模跟踪的所有方面。 我们最终开发了一个旨在利用这些数据的基线模型。 我们通过对数据的训练表明，该方法能够胜过仅用边界框轨迹和单个图像实例分割掩模训练的方法。 我们的新数据集使这种联合训练成为可能，这为未来的研究提供了许多机会。



