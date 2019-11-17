#include <iostream>
#include <string>
using namespace std;

const int CHN_NUM_CHAR_COUNT  = 10;
const int CHN_CHAR_LENGTH = 2;
typedef struct
{
	const char* name;                 //中文节权位名称
	int value;                        //10的倍数
	bool secUnit;                     //是否为节权位
}CHN_NAME_VALUE;

CHN_NAME_VALUE chnValuePair[]=
{
	{"十", 10, false}, {"百", 100, false}, {"千", 1000, false}, {"万", 10000, true}, {"亿", 100000000, true}
};

const char *chnNumChar[CHN_NUM_CHAR_COUNT] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
const char *chnUnitSection[] = {"", "万", "亿", "万亿"};
const char *chnUnitChar[] = {"", "十", "百", "千"};

//*************************************************************将数字转换为中文字符*************************************************

// 将一个节的数字转换为中文数字，照表
void SectionToChinese (unsigned int section, string & chnStr)
{
	string strIns;
	int unitPos = 0;
	bool zero = true;
	while (section > 0)
	{
		int v = section % 10;
		if (v == 0)
		{
			if (section == 0 || !zero)
			{
				zero = true;                   //需要补零，zero作用是确保对于连串的零只补一个零
				chnStr.insert (0, chnNumChar[v]);
			}
		}
		else
		{
			zero = false;                     //至少有一个数组不是零
			strIns = chnNumChar[v];           //此位对应的中文数字
			strIns += chnUnitChar[unitPos];   //此位对应的中文权位
			chnStr.insert (0, strIns);
		}
		unitPos++;                           //移位
		section = section / 10;
	}
}


//主要函数
void NumberToChinese (unsigned int num, string &chnStr)
{
	if (num == 0)  
	{
		chnStr = "零";
		return;
	}
	int unitPos = 0;
	bool needZero = false;
	//std::string strIns;
	while (num > 0)
	{
		string strIns;
		unsigned int section = num % 10000;
		if (needZero)
			chnStr.insert (0, chnNumChar[0]);
		SectionToChinese (section, strIns);                            //是否需要节权位

		strIns += (section != 0) ? chnUnitSection[unitPos] : chnUnitSection[0];


		chnStr.insert (0, strIns);                                    //千位是？需要在下一个section位置补零
		needZero = (section < 1000) && (section > 0);
		num = num / 10000;
		unitPos++;
	}

}

//***************************************************将中文数字转换为数字*********************************
//找到中文的两个字节的数字对应的阿拉伯数字
int ChineseToValue (string &chnStr)
{
	for (int i = 0; i < 10; i++)                    //找到中文的两个字节的数字对应的阿拉伯数字
	{
		if (chnStr.compare (chnNumChar[i]) == 0)
			return i;
	}
	return -1;
}

//转换节权位
int ChineseToUnit (string &chnStr, bool &secUnit)
{
	for (int i = 0; i < 5; i++)                    //找到对应的权位
	{
		if(chnStr.compare (chnValuePair[i].name ) == 0	)
		{
			secUnit = chnValuePair[i].secUnit ;         //是否为节权位
			return chnValuePair[i].value ;

		}
	}
	return -1;
}

// 主要函数
unsigned int ChineseToNumber (const string &chnStr)
{
	unsigned int rtn = 0;                              //最后的结果
	unsigned int section = 0;                          //同上
	int number = 0;
	bool secUnit = false;
	std::string::size_type pos = 0;                   //string 对象的索引
	while (pos < chnStr.length ())
	{
		int num = ChineseToValue (chnStr.substr (pos, CHN_CHAR_LENGTH));              //返回值为-1 表示为节权位 ，需要转换
		                                                              // ChineseToValue 函数将中文数字转换为阿拉伯数字
		if (num >= 0)
		{
			number = num;
			pos += CHN_CHAR_LENGTH;
			if (pos >= chnStr.length ())
			{
				section += number;
				rtn += section;
				break;
			}
		}
		else 
		{
			int unit = ChineseToUnit (chnStr.substr (pos, CHN_CHAR_LENGTH), secUnit);
		
			if (secUnit)
			{
				section = (section + number) * unit;
				rtn += section;
				section = 0;
			}
			else 
			{
				section += (number * unit);
			}
			number = 0;
			pos += CHN_CHAR_LENGTH;
			if (pos >= chnStr.length () )
			{
				rtn += section;
				break;
			}
		}
	}
	return rtn;
}



//测试程序
void main ()
{
	unsigned int num = 200010;
	string chnStr;
	NumberToChinese (num, chnStr);
	cout << chnStr << endl;

	unsigned int n = ChineseToNumber (chnStr);
	cout << n << endl;
}