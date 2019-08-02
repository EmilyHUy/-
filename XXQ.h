#ifndef XXQ_H
#define XXQ_H

#include <iostream>
#include <string>
#include<stdlib.h>
#include<vector>
#include<fstream>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <locale>  
using namespace std;

#define MAXLEN 20
#define MAXNUM 60


typedef struct
{
	string mStuNo;
	string mStuName;
	double mHomeworkScoe = 0.0;
	double mLabScore = 0.0;
	double mQ1Score = 0.0;
	double mQ2Score = 0.0;
	double mQ3Score = 0.0;
	double mFinalworkScore = 0.0;
	double mFinalScore = 0.0;
}STUINFO;



class CStudent
{
public:
	CStudent();
	~CStudent();
	void readExcel(CString strFilePath);
	int GETNUM();
	string Trim(string& str);
	void InputRatio(double QM, double HW, double LAB,double S1,double S2,double S3);//输入成绩比例以及期末考试题目满分
	void CalFinalScore();//按照输入的比例计算期末最终成绩
	void CalAverage();//计算平均成绩以及题目得分率
	void OutputStatistics(CString);//输出统计数据
	//最高分，最低分
	void ScoreLevel();//成绩分段，优秀率，及格率
	void CalAchieve();//达成度
private:
	int mStuNum;
	double mRatioTest;//考试占比
	double mRatioHWork;//homeworkRatio
	double mRatioLab;//LabRatio
	double mScore1;
	double mScore2;
	double mScore3;//满分
	double mScoringRate1;
	double mScoringRate2;
	double mScoringRate3;//得分率
	double mAvg;//平均分
	double mLow, mHigh;//最高分最低分
	double mPassRate;//及格率
	double mPerfactRate;
	int mFail, mNum60, mNum70, mNum80, mNum90;
	//不及格人数，60--70人数，70--80人数，80--90人数，90--100人数
	int mPerfact, mPass;//优秀人数，通过人数
	double mRate60, mRate70, mRate80, mRate90;//分段比例
	double mAchievePoint;//达成度
	double minScore;		//题型得分最高
	CString ScoringRateEva;
	CString AchEva;			//达成度评价
	STUINFO mStu[MAXNUM];
};


#endif // !XXQ_H


