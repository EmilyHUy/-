// XXQ.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "stdafx.h"
#include "pch.h"

//#include<unistd.h>
#include "XXQ.h"

CStudent::CStudent()
{
	mStuNum = 0;
	mRatioTest = 1.0;
	mRatioHWork = 1.0;
	mRatioLab = 1.0;
	mScore1 = 0.0;
	mScore2 = 0.0;
	mScore3 = 0.0;
	mScoringRate1 = 1.0;
	mScoringRate2 = 1.0;
	mScoringRate3 = 1.0;
	mAvg = 0.0;
	mLow = 0.0;
	mHigh = 0.0;
	mPassRate = 1.0;
	mPerfactRate = 1.0;
	mFail = 0; 
	mNum60 = 0;
	mNum70 = 0; 
	mNum80 = 0; 
	mNum90 = 0;
	mAchievePoint = 1.0;
	mRate60 = 1.0;
	mRate70 = 1.0;
	mRate80 = 1.0;
	mRate90 = 1.0;
	mPass = 0;
	mPerfact = 1.0;
}

CStudent::~CStudent()
{

}

int CStudent::GETNUM()
{
	return mStuNum;
}

void CStudent::InputRatio(double QM, double HW, double LAB, double S1, double S2, double S3)
{
	/*double RatioT, RatioH, RatioL;
	RatioT = 1.0;
	RatioL = 1.0;
	RatioH = 1.0;*/

	//cout << "Input the FinalTest's contribution: ";
	mRatioTest = QM;
	//cout << endl;

	//cout << "Input the Homework's contribution: ";
	mRatioHWork = HW;
	//cout << endl;

	//cout << "Input the Lab's contribution: ";
	mRatioLab = LAB;
	//cout << endl;

	//cout << "Input the FULL mark of Q1: ";
	mScore1 = S1;
	//cout << endl;

	//cout << "Input the FULL mark of Q2: ";
	mScore2 = S2;
	//cout << endl;

	//cout << "Input the FULL mark of Q3: ";
	mScore3 = S3;
	//cout << endl;
}

void CStudent::CalFinalScore()
{
	for (int i = 0; i < mStuNum; i++)
	{
		mStu[i].mFinalScore = mStu[i].mFinalworkScore*mRatioTest + mStu[i].mHomeworkScoe*mRatioHWork + mStu[i].mLabScore*mRatioLab;
	}
}

void CStudent::CalAverage()
{
	
	double tempQ1 = 0.0;
	double tempQ2 = 0.0;
	double tempQ3 = 0.0;
	double tempF = 0.0;
	for (int i = 0; i < mStuNum; i++)
	{
		tempQ1 += mStu[i].mQ1Score;
		tempQ2 += mStu[i].mQ2Score;
		tempQ3 += mStu[i].mQ3Score;
		tempF += mStu[i].mFinalScore;
	}
	//期末考试题目得分率
	double avg1 = tempQ1 / mStuNum;
	double avg2 = tempQ2 / mStuNum;
	double avg3 = tempQ3 / mStuNum;
	mScoringRate1 = avg1 / mScore1;
	mScoringRate2 = avg2 / mScore2;
	mScoringRate3 = avg3 / mScore3;
	//期末最终成绩平均分
	mAvg = tempF / mStuNum;
}

void CStudent::OutputStatistics(CString strFilePath)
{
	//readExcel(strFilePath);
	//cout << "学生人数：" << mStuNum << endl;
	CString temp_value0 = _T("");   //temp_value用来处理int值
	temp_value0.Format(_T("%d"), mStuNum);//固定格式
	LPCTSTR pStr0 = LPCTSTR(temp_value0);
	//作业占比
	CString temp_value1 = _T("");   //temp_value用来处理int值
	temp_value1.Format(_T("%lf"), mRatioHWork);//固定格式
	LPCTSTR pStr1 = LPCTSTR(temp_value1);
	//考试占比
	CString temp_value2 = _T("");   //temp_value用来处理int值
	temp_value2.Format(_T("%.2lf"), mRatioTest);//固定格式
	LPCTSTR pStr2 = LPCTSTR(temp_value1);

	//实验占比
	CString temp_value3 = _T("");   //temp_value用来处理int值
	temp_value3.Format(_T("%.2lf"), mRatioLab);//固定格式
	LPCTSTR pStr3 = LPCTSTR(temp_value3);

	//不及格人数
	CString temp_value4 = _T("");   //temp_value用来处理int值
	temp_value4.Format(_T("%d"), mFail);//固定格式
	LPCTSTR pStr4 = LPCTSTR(temp_value4);

	//60-70
	CString temp_value5 = _T("");   //temp_value用来处理int值
	temp_value5.Format(_T("%d"), mNum60);//固定格式
	LPCTSTR pStr5 = LPCTSTR(temp_value5);

	//70-80
	CString temp_value6 = _T("");   //temp_value用来处理int值
	temp_value6.Format(_T("%d"), mNum70);//固定格式
	LPCTSTR pStr6 = LPCTSTR(temp_value6);

	//80-90
	CString temp_value7 = _T("");   //temp_value用来处理int值
	temp_value7.Format(_T("%d"), mNum80);//固定格式
	LPCTSTR pStr7 = LPCTSTR(temp_value7);

	//90-100
	CString temp_value8 = _T("");   //temp_value用来处理int值
	temp_value8.Format(_T("%d"), mNum90);//固定格式
	LPCTSTR pStr8 = LPCTSTR(temp_value8);

	//及格
	CString temp_value9 = _T("");   //temp_value用来处理int值
	temp_value9.Format(_T("%.2lf"), mPassRate);//固定格式
	LPCTSTR pStr9 = LPCTSTR(temp_value9);

	//优秀率
	CString temp_value10 = _T("");   //temp_value用来处理int值
	temp_value10.Format(_T("%.2lf"), mPerfactRate);//固定格式
	LPCTSTR pStr10 = LPCTSTR(temp_value10);

	//avg
	CString temp_value11 = _T("");   //temp_value用来处理int值
	temp_value11.Format(_T("%.2lf"), mAvg);//固定格式
	LPCTSTR pStr11 = LPCTSTR(temp_value11);

	//满分1
	CString temp_value12 = _T("");   //temp_value用来处理int值
	temp_value12.Format(_T("%d"), mScore1);//固定格式
	LPCTSTR pStr12 = LPCTSTR(temp_value12);

	//得分1
	CString temp_value13 = _T("");   //temp_value用来处理int值
	temp_value13.Format(_T("%.2lf"), mScoringRate1);//固定格式
	LPCTSTR pStr13 = LPCTSTR(temp_value13);

	//满分2
	CString temp_value14 = _T("");   //temp_value用来处理int值
	temp_value14.Format(_T("%d"), mScore2);//固定格式
	LPCTSTR pStr14 = LPCTSTR(temp_value14);

	//得分2
	CString temp_value15 = _T("");   //temp_value用来处理int值
	temp_value15.Format(_T("%.2lf"), mScoringRate2);//固定格式
	LPCTSTR pStr15 = LPCTSTR(temp_value15);

	//满分3
	CString temp_value16 = _T("");   //temp_value用来处理int值
	temp_value16.Format(_T("%d"), mScore3);//固定格式
	LPCTSTR pStr16 = LPCTSTR(temp_value16);

	//得分3
	CString temp_value17 = _T("");   //temp_value用来处理int值
	temp_value17.Format(_T("%.2lf"), mScoringRate3);//固定格式
	LPCTSTR pStr17 = LPCTSTR(temp_value17);

	//不及格率
	CString temp_value18 = _T("");   //temp_value用来处理int值
	temp_value18.Format(_T("%.2lf"), 1-mPassRate);//固定格式
	LPCTSTR pStr18 = LPCTSTR(temp_value18);

	//优秀人数
	CString temp_value19 = _T("");   //temp_value用来处理int值
	temp_value19.Format(_T("%d"), mPerfact);//固定格式
	LPCTSTR pStr19 = LPCTSTR(temp_value19);

	//及格人数
	CString temp_value20 = _T("");   //temp_value用来处理int值
	temp_value20.Format(_T("%d"), mPass);//固定格式
	LPCTSTR pStr20 = LPCTSTR(temp_value20);

	//ratio
	//60-70
	CString temp_value21 = _T("");   //temp_value用来处理int值
	temp_value21.Format(_T("%.2lf"), mRate60);//固定格式
	LPCTSTR pStr21 = LPCTSTR(temp_value21);

	//70-80
	CString temp_value22 = _T("");   //temp_value用来处理int值
	temp_value22.Format(_T("%.2lf"), mRate70);//固定格式
	LPCTSTR pStr22 = LPCTSTR(temp_value22);

	//80-90
	CString temp_value23 = _T("");   //temp_value用来处理int值
	temp_value23.Format(_T("%.2lf"), mRate80);//固定格式
	LPCTSTR pStr23 = LPCTSTR(temp_value23);

	//achieve
	CString temp_value24 = _T("");   //temp_value用来处理int值
	temp_value24.Format(_T("%.2lf"), mAchievePoint);//固定格式
	LPCTSTR pStr24 = LPCTSTR(temp_value24);

	//max
	CString temp_value25 = _T("");   //temp_value用来处理int值
	temp_value25.Format(_T("%.2lf"), mHigh);//固定格式
	LPCTSTR pStr25 = LPCTSTR(temp_value25);

	if (mAchievePoint < 0.6)
	{
		AchEva = "，未达到教学目标。";
	}
	else if (mAchievePoint >= 0.6&&mAchievePoint < 0.75)
	{
		AchEva = "，基本达到了教学目标。";
	}
	else
	{
		AchEva = "，较好地完成了教学目标。";
	}
	CString temp_eva1 = _T("");   //temp_eva用来处理string值
	temp_eva1.Format(_T("%ls"), AchEva);//固定格式
	LPCTSTR pStr26 = LPCTSTR(temp_eva1);

	double a, b, c, temp = 0.0;
	a = mScoringRate1;
	b = mScoringRate2;
	c = mScoringRate3;
	if (a > b)			//三题得分率按从小到大排序，最小为a
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	minScore = a;

	if (minScore == mScoringRate1)
		ScoringRateEva = "选择题准确率不高，出现问题主要是对知识的深入理解上；\
主观性试题问题突出，主要表现是第一，基础理论记忆不扎实，\
其次是理论的准确性不够，三是实际应用能力有待提高。";
	else if (minScore == mScoringRate2)
		ScoringRateEva = "计算题准确率不高，因为计算题多数是知识记忆型和\
理解型的题目，由此可见学生对记忆、理解、计算等方面的基础知识\
掌握不够扎实的。";
	else if(minScore == mScoringRate3)
		ScoringRateEva =  "应用题得分率不高，解答应用题是分析问题和解决问题\
能力的高层次的反应，能较好地考察学生在学习新知、理解分析问题\
的应用、归纳、总结、探索等方面的能力，由此可以看出学生对应用\
题的理解、分析及题型的变换的应变能力较差，实际操作能力不强。";

	//题型评价
	CString temp_eva0 = _T("");   //temp_eva用来处理string值
	temp_eva0.Format(_T("%ls"), ScoringRateEva);//固定格式
	LPCTSTR pStr27 = LPCTSTR(temp_eva0);

	////min
	//CString temp_value26 = _T("");   //temp_value用来处理int值
	//temp_value26.Format(_T("%.2lf"), mLow);//固定格式
	//LPCTSTR pStr26 = LPCTSTR(temp_value26);

	COleVariant	covZero((short)0),
		covTrue((short)TRUE),
		covFalse((short)FALSE),
		covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR),
		covDocxType((short)0),
		start_line, end_line,
		dot(_T("F:\\Fine\\大三下\\小学期\\面向课程目标达成度的成绩分析16281064呼延琳璐16271193贾梦洁\\ScoreAnalyzeSystem\\docs\\Analysis.dot"));

	CApplication wordApp;
	CDocuments docs;
	CDocument0 docx;
	CBookmarks bookmarks;
	CBookmark0 bookmark;
	CRange range;
	CCell cell;
	if (!wordApp.CreateDispatch(_T("Word.Application")))
	{
		AfxMessageBox(_T("本机没有安装word产品！"));
		return;
	}
	//////////////////////begin//////////////////////

	//CStudent cstu;
	
	int num = -2;
	num = GETNUM();
	//cout << num;
	CString temp_value = _T("");   //temp_value用来处理int值
	temp_value.Format(_T("%d"), num);//固定格式
	LPCTSTR pStr = LPCTSTR(temp_value);
	
	wordApp.put_Visible(FALSE);
	CString wordVersion = wordApp.get_Version();
	docs = wordApp.get_Documents();
	docx = docs.Add(dot, covOptional, covOptional, covOptional);
	bookmarks = docx.get_Bookmarks();

	bookmark = bookmarks.Item(&_variant_t(_T("学院")));
	range = bookmark.get_Range();
	range.put_Text(_T("计算机与信息技术学院"));

	bookmark = bookmarks.Item(&_variant_t(_T("专业")));
	range = bookmark.get_Range();
	range.put_Text(_T("计算机科学与技术"));

	bookmark = bookmarks.Item(&_variant_t(_T("fail")));//不及格人数
	range = bookmark.get_Range();
	range.put_Text(pStr4);
	//AfxMessageBox(temp_value4);

	bookmark = bookmarks.Item(&_variant_t(_T("failRate")));//不及格率
	range = bookmark.get_Range();
	range.put_Text(pStr18);
	//AfxMessageBox(temp_value18);

	bookmark = bookmarks.Item(&_variant_t(_T("num60")));
	range = bookmark.get_Range();
	range.put_Text(pStr5);
	//AfxMessageBox(temp_value5);

	bookmark = bookmarks.Item(&_variant_t(_T("num70")));
	range = bookmark.get_Range();
	range.put_Text(pStr6);
	//AfxMessageBox(temp_value6);

	bookmark = bookmarks.Item(&_variant_t(_T("num80")));
	range = bookmark.get_Range();
	range.put_Text(pStr7);
	//AfxMessageBox(temp_value7);

	bookmark = bookmarks.Item(&_variant_t(_T("num90")));
	range = bookmark.get_Range();
	range.put_Text(pStr8);
	//AfxMessageBox(temp_value8);

	////rate60,70,80,90
	bookmark = bookmarks.Item(&_variant_t(_T("rate60")));
	range = bookmark.get_Range();
	range.put_Text(pStr21);

	bookmark = bookmarks.Item(&_variant_t(_T("rate70")));
	range = bookmark.get_Range();
	range.put_Text(pStr22);

	bookmark = bookmarks.Item(&_variant_t(_T("rate80")));
	range = bookmark.get_Range();
	range.put_Text(pStr23);

	bookmark = bookmarks.Item(&_variant_t(_T("rate90")));
	range = bookmark.get_Range();
	range.put_Text(pStr10);
	////solution

	bookmark = bookmarks.Item(&_variant_t(_T("优秀人数")));
	range = bookmark.get_Range();
	range.put_Text(pStr19);

	bookmark = bookmarks.Item(&_variant_t(_T("优秀率")));
	range = bookmark.get_Range();
	range.put_Text(pStr10);

	bookmark = bookmarks.Item(&_variant_t(_T("及格人数")));
	range = bookmark.get_Range();
	range.put_Text(pStr20);

	bookmark = bookmarks.Item(&_variant_t(_T("及格率")));
	range = bookmark.get_Range();
	range.put_Text(pStr9);

	bookmark = bookmarks.Item(&_variant_t(_T("平均分")));
	range = bookmark.get_Range();
	range.put_Text(pStr11);

	bookmark = bookmarks.Item(&_variant_t(_T("应用题得分率")));
	range = bookmark.get_Range();
	range.put_Text(pStr17);

	bookmark = bookmarks.Item(&_variant_t(_T("总人数")));
	range = bookmark.get_Range();
	range.put_Text(pStr0);

	bookmark = bookmarks.Item(&_variant_t(_T("计算题得分率")));
	range = bookmark.get_Range();
	range.put_Text(pStr15);

	bookmark = bookmarks.Item(&_variant_t(_T("选择题得分率")));
	range = bookmark.get_Range();
	range.put_Text(pStr13);

	bookmark = bookmarks.Item(&_variant_t(_T("ACHIEVE")));
	range = bookmark.get_Range();
	range.put_Text(pStr24);

	bookmark = bookmarks.Item(&_variant_t(_T("MAX")));
	range = bookmark.get_Range();
	range.put_Text(pStr25);

	bookmark = bookmarks.Item(&_variant_t(_T("solution0")));
	range = bookmark.get_Range();
	range.put_Text(_T("本次考试有"));

	bookmark = bookmarks.Item(&_variant_t(_T("solution1")));
	range = bookmark.get_Range();
	range.put_Text(pStr0);

	bookmark = bookmarks.Item(&_variant_t(_T("solution2")));
	range = bookmark.get_Range();
	range.put_Text(_T("人参加，平均分为"));

	bookmark = bookmarks.Item(&_variant_t(_T("solution3")));
	range = bookmark.get_Range();
	range.put_Text(pStr11);

	bookmark = bookmarks.Item(&_variant_t(_T("solution4")));
	range = bookmark.get_Range();
	range.put_Text(_T("分，课程达成度为"));

	bookmark = bookmarks.Item(&_variant_t(_T("solution5")));
	range = bookmark.get_Range();
	range.put_Text(pStr24);

	bookmark = bookmarks.Item(&_variant_t(_T("solution6")));
	range = bookmark.get_Range();
	range.put_Text(pStr26);

	bookmark = bookmarks.Item(&_variant_t(_T("solution7")));
	range = bookmark.get_Range();
	range.put_Text(_T("对于该套试卷，"));

	bookmark = bookmarks.Item(&_variant_t(_T("solution8")));
	range = bookmark.get_Range();
	range.put_Text(pStr27);

	bookmark = bookmarks.Item(&_variant_t(_T("solution9")));
	range = bookmark.get_Range();
	range.put_Text(_T("在以后的课程中，主要采用预习引导、\
换位模拟、课堂讨论、联想的教学方法，具体实现采用板书与\
多媒体相结合的方法。提高教师的个体素质，注重高校教师队伍\
整体素质的提高和队伍结构的优化，加强学术交流，使用效果良好\
的教材，争取自编练习册及其配套辅导书，更好地实现人才培养的\
目标服务"));


	//CString strSavePath = _T("F:");
	//strSavePath += _T("\\Fine\\大三下\\小学期\\面向课程目标达成度的成绩分析16281064呼延琳璐16271193贾梦洁\\ScoreAnalyzeSystem\\docs\\学生成绩分析表.docx");
	/*docx.SaveAs(COleVariant(strSavePath), covOptional, covOptional, covOptional, covOptional,
		covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional);
	*/
	TCHAR CurrentDirectory[MAX_PATH];
	CString fileName =_T( "*.docx");         //默认打开的文件名 
	CString FilePathName;
	CString Directory;
	CString SaveFileName;
	int ret = GetCurrentDirectory(MAX_PATH, CurrentDirectory);
	Directory.Format(_T("%s"), CurrentDirectory);
	SaveFileName = Directory + _T("\\test.docx");
	TCHAR filter[] = _T("文件 (*.docx)|*.docx||");   //文件过虑的类型  
	CFileDialog openFileDlg(TRUE, NULL, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	if (openFileDlg.DoModal() == IDOK)
	{
		FilePathName = openFileDlg.GetPathName(); //文件名保存在了FilePathName里
		CopyFile(FilePathName, SaveFileName, FALSE);
	}
	else
	{
		return;
	}
	docx.SaveAs(COleVariant(FilePathName), covOptional, covOptional, covOptional, covOptional,
		covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional);


	// 退出word应用
	docx.Close(covFalse, covOptional, covOptional);
	wordApp.Quit(covOptional, covOptional, covOptional);
	range.ReleaseDispatch();
	bookmarks.ReleaseDispatch();
	wordApp.ReleaseDispatch();
	
}

void CStudent::readExcel(CString strFilePath)
{
	//char filename[MAXLEN] = { '\0' };
	//cout << "Please input the file name: ";
	//cin >> filename;
	ifstream inFile(strFilePath, ios::in);
	if (inFile.fail()) 
	{ 
		//cout << "File not found" << endl;
		AfxMessageBox(_T("File not found"));
		return;
	}
	string line;
	int stuCount = -1;//calculate the students' num
	//CStudent stu;
	
	while (getline(inFile, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
	{
		stuCount++;
		if (stuCount <= 0)
			continue;
		//cout << stuCount;
		//cout << "原始字符串：" << line << endl; //整行输出
		istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
		vector<string> fields; //声明一个字符串向量
		string field;
		while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
		{
			fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
		}
		
		mStu[stuCount].mStuNo = Trim(fields[0]);
		mStu[stuCount].mStuName = Trim(fields[1]);

		stringstream temp;
		temp << Trim(fields[2]);
		temp >> mStu[stuCount].mHomeworkScoe;
		temp.clear();

		temp << Trim(fields[3]);
		temp >> mStu[stuCount].mFinalworkScore;
		temp.clear();

		temp << Trim(fields[4]);
		temp >> mStu[stuCount].mQ1Score;
		temp.clear();

		temp << Trim(fields[5]);
		temp >> mStu[stuCount].mQ2Score;
		temp.clear();

		temp << Trim(fields[6]);
		temp >> mStu[stuCount].mQ3Score;
		temp.clear();

		temp << Trim(fields[7]);
		temp >> mStu[stuCount].mLabScore;
		temp.clear();

		//string name = Trim(fields[0]); //清除掉向量fields中第一个元素的无效字符，并赋值给变量name
		//string age = Trim(fields[1]); //清除掉向量fields中第二个元素的无效字符，并赋值给变量age
		//string birthday = Trim(fields[2]); //清除掉向量fields中第三个元素的无效字符，并赋值给变量birthday
		//cout << "处理之后的字符串：" << name << "\t" << age << "\t" << birthday << endl;
	}
	mStuNum = stuCount;
	//getchar();
}

string CStudent::Trim(string& str)
{
	//str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
	str.erase(0, str.find_first_not_of(" \t\r\n"));
	str.erase(str.find_last_not_of(" \t\r\n") + 1);
	return str;
}

int compare(const void *a, const void *b)
{
	STUINFO *pa = (STUINFO *)a;
	STUINFO *pb = (STUINFO *)b;

	double num1 = pa->mFinalScore;
	double num2 = pb->mFinalScore;

	return num2 - num1;
}

void CStudent::ScoreLevel()
{
	int i = 0;


	qsort(mStu, MAXNUM, sizeof(STUINFO), compare);		//大到小排序

	mHigh = mStu[0].mFinalScore;
	mLow = mStu[mStuNum-1].mFinalScore;

	//cout << "最高分：" << mHigh << endl;
	//cout << "最低分： " << mLow << endl;

	for (i = 0; i < mStuNum; i++)
	{
		if (mStu[i].mFinalScore >= 90)
		{
			mNum90++;
		}
		else if (mStu[i].mFinalScore >= 80 && mStu[i].mFinalScore < 90)
		{
			mNum80++;
		}
		else if (mStu[i].mFinalScore >= 70 && mStu[i].mFinalScore < 80)
		{
			mNum70++;
		}
		else if (mStu[i].mFinalScore >= 60 && mStu[i].mFinalScore < 70)
		{
			mNum60++;
		}
		else
			mFail++;
	}

	mPassRate = 1.0*(mStuNum - mFail) / mStuNum;
	mPerfactRate = 1.0*mNum90 / mStuNum;
	mPass = mStuNum - mFail;
	mPerfact = mNum90;
	mRate60 = 1.0*mNum60 / mStuNum;
	mRate70 = 1.0*mNum70 / mStuNum;
	mRate80 = 1.0*mNum80 / mStuNum;
	mRate90 = 1.0*mNum90 / mStuNum;
	
	cout << fixed << setprecision(2);

}

void CStudent::CalAchieve()
{

	mAchievePoint = mAvg /100.0;
}

