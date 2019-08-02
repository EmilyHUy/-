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
	void InputRatio(double QM, double HW, double LAB,double S1,double S2,double S3);//����ɼ������Լ���ĩ������Ŀ����
	void CalFinalScore();//��������ı���������ĩ���ճɼ�
	void CalAverage();//����ƽ���ɼ��Լ���Ŀ�÷���
	void OutputStatistics(CString);//���ͳ������
	//��߷֣���ͷ�
	void ScoreLevel();//�ɼ��ֶΣ������ʣ�������
	void CalAchieve();//��ɶ�
private:
	int mStuNum;
	double mRatioTest;//����ռ��
	double mRatioHWork;//homeworkRatio
	double mRatioLab;//LabRatio
	double mScore1;
	double mScore2;
	double mScore3;//����
	double mScoringRate1;
	double mScoringRate2;
	double mScoringRate3;//�÷���
	double mAvg;//ƽ����
	double mLow, mHigh;//��߷���ͷ�
	double mPassRate;//������
	double mPerfactRate;
	int mFail, mNum60, mNum70, mNum80, mNum90;
	//������������60--70������70--80������80--90������90--100����
	int mPerfact, mPass;//����������ͨ������
	double mRate60, mRate70, mRate80, mRate90;//�ֶα���
	double mAchievePoint;//��ɶ�
	double minScore;		//���͵÷����
	CString ScoringRateEva;
	CString AchEva;			//��ɶ�����
	STUINFO mStu[MAXNUM];
};


#endif // !XXQ_H


