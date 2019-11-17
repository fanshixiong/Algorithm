#include <iostream>
#include <string>
using namespace std;

const int CHN_NUM_CHAR_COUNT  = 10;
const int CHN_CHAR_LENGTH = 2;
typedef struct
{
	const char* name;                 //���Ľ�Ȩλ����
	int value;                        //10�ı���
	bool secUnit;                     //�Ƿ�Ϊ��Ȩλ
}CHN_NAME_VALUE;

CHN_NAME_VALUE chnValuePair[]=
{
	{"ʮ", 10, false}, {"��", 100, false}, {"ǧ", 1000, false}, {"��", 10000, true}, {"��", 100000000, true}
};

const char *chnNumChar[CHN_NUM_CHAR_COUNT] = {"��", "һ", "��", "��", "��", "��", "��", "��", "��", "��"};
const char *chnUnitSection[] = {"", "��", "��", "����"};
const char *chnUnitChar[] = {"", "ʮ", "��", "ǧ"};

//*************************************************************������ת��Ϊ�����ַ�*************************************************

// ��һ���ڵ�����ת��Ϊ�������֣��ձ�
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
				zero = true;                   //��Ҫ���㣬zero������ȷ��������������ֻ��һ����
				chnStr.insert (0, chnNumChar[v]);
			}
		}
		else
		{
			zero = false;                     //������һ�����鲻����
			strIns = chnNumChar[v];           //��λ��Ӧ����������
			strIns += chnUnitChar[unitPos];   //��λ��Ӧ������Ȩλ
			chnStr.insert (0, strIns);
		}
		unitPos++;                           //��λ
		section = section / 10;
	}
}


//��Ҫ����
void NumberToChinese (unsigned int num, string &chnStr)
{
	if (num == 0)  
	{
		chnStr = "��";
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
		SectionToChinese (section, strIns);                            //�Ƿ���Ҫ��Ȩλ

		strIns += (section != 0) ? chnUnitSection[unitPos] : chnUnitSection[0];


		chnStr.insert (0, strIns);                                    //ǧλ�ǣ���Ҫ����һ��sectionλ�ò���
		needZero = (section < 1000) && (section > 0);
		num = num / 10000;
		unitPos++;
	}

}

//***************************************************����������ת��Ϊ����*********************************
//�ҵ����ĵ������ֽڵ����ֶ�Ӧ�İ���������
int ChineseToValue (string &chnStr)
{
	for (int i = 0; i < 10; i++)                    //�ҵ����ĵ������ֽڵ����ֶ�Ӧ�İ���������
	{
		if (chnStr.compare (chnNumChar[i]) == 0)
			return i;
	}
	return -1;
}

//ת����Ȩλ
int ChineseToUnit (string &chnStr, bool &secUnit)
{
	for (int i = 0; i < 5; i++)                    //�ҵ���Ӧ��Ȩλ
	{
		if(chnStr.compare (chnValuePair[i].name ) == 0	)
		{
			secUnit = chnValuePair[i].secUnit ;         //�Ƿ�Ϊ��Ȩλ
			return chnValuePair[i].value ;

		}
	}
	return -1;
}

// ��Ҫ����
unsigned int ChineseToNumber (const string &chnStr)
{
	unsigned int rtn = 0;                              //���Ľ��
	unsigned int section = 0;                          //ͬ��
	int number = 0;
	bool secUnit = false;
	std::string::size_type pos = 0;                   //string ���������
	while (pos < chnStr.length ())
	{
		int num = ChineseToValue (chnStr.substr (pos, CHN_CHAR_LENGTH));              //����ֵΪ-1 ��ʾΪ��Ȩλ ����Ҫת��
		                                                              // ChineseToValue ��������������ת��Ϊ����������
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



//���Գ���
void main ()
{
	unsigned int num = 200010;
	string chnStr;
	NumberToChinese (num, chnStr);
	cout << chnStr << endl;

	unsigned int n = ChineseToNumber (chnStr);
	cout << n << endl;
}