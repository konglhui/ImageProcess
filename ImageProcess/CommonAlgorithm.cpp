#include "stdafx.h"
#include "CommonAlgorithm.h"
//
//bool CommonAlgorithm::gaussionSolveMatrix(std::vector<std::vector<double>> matrix, std::vector<double> &output_matrix)
//{
//	{
//		//�������ǿ�
//		if (matrix.empty() == true)
//		{
//			return false;
//		}
//		int width = matrix[0].size();
//		int height = matrix.size();
//
//		//���м���Ϊ0ʱ���޷����㣬����Ҫ��֤�м��Ϊ0
//		for (int i = 0; i < width - 1; i++)
//		{
//			int k = 0;
//			while (matrix[i][i] == 0 && k < (width - 1)*height)
//			{
//				for (int j = 0; j < height; j++)
//				{
//					if (j == i) continue;
//					if (/*matrix[j][i] != 0 && */matrix[i][j] != 0)
//					{
//						int n = 0;
//						for (; n < width - 1;)
//						{
//							if ((matrix[i][n] == 0 && matrix[j][n] == 0) || (matrix[i][n] != 0 && matrix[j][n] != 0))
//								n++;
//							else
//								break;
//						}
//						if (n == width - 1)
//						{
//							continue;
//						}
//						swap<std::vector<double>>(matrix[i], matrix[j]);
//						break;
//					}
//				}
//				k++;
//			}
//			if (matrix[i][i] == 0) return false;
//		}
//
//
//		//ѭ������
//		for (int i = 0; i < width - 2; i++)
//		{
//			for (int j = i + 1; j < height; j++)
//			{
//				if (matrix[j][i] != 0)
//				{
//					int temp_value = matrix[j][i];
//					for (int k = 0; k < width; k++)
//					{
//						matrix[j][k] = matrix[j][k] / temp_value * matrix[i][i] - matrix[i][k];;
//					}
//				}
//
//			}
//		}
//
//
//
//
//		//������-1 ����
//		if (width - 1 > height)
//		{
//			return false;
//		}
//		//����-1����ȥ���������õľ���
//		else if (width - 1 < height)
//		{
//			//����������������ʱ���ܻ���֣�ĳ������ȫһ����������ȫΪ0
//			//��Ϊ����������ǵ㣬���������������ȫһ�������Դ�ѭ���������͸�Ӻͷ�����ûʲô���á�
//			for (int i = 0; i < width - 1; i++)
//			{
//				if (matrix[i][i] == 0)
//				{
//					for (int j = 0; j < height; j++)
//					{
//						if (j == i) continue;
//						if (matrix[j][i] != 0 /*&& matrix[i][j] != 0*/)
//						{
//							swap<std::vector<double>>(matrix[i], matrix[j]);
//							break;
//						}
//					}
//				}
//				if (matrix[i][i] == 0) return false;
//			}
//			for (int i = width - 1; i != height; )
//			{
//				matrix.pop_back();
//				height--;
//			}
//		}
//
//
//		//ѭ������
//		for (int i = width - 2; i > -1; i--)
//		{
//			for (int j = i - 1; j > -1; j--)
//			{
//				if (matrix[j][i] != 0)
//				{
//					double temp_value = matrix[j][i];
//					for (int k = 0; k < width; k++)
//					{
//						matrix[j][k] = matrix[j][k] / temp_value * matrix[i][i] - matrix[i][k];
//					}
//				}
//			}
//		}
//
//		//������
//		for (int i = 0; i < height; i++)
//		{
//			if (matrix[i][i] == 0)
//				return false;
//			output_matrix.push_back(matrix[i][height] / matrix[i][i]);
//		}
//		return true;
//	}
//
//
//
//
//	////�������ǿ�
//	//if (matrix.empty() == true)
//	//{
//	//	return false;
//	//}
//	//int width = matrix[0].size();
//	//int height = matrix.size();
//
//	//auto a = [&]()->bool
//	//{
//	//	bool is_ok = false;
//	//	for (int i = 0; i < width - 2; i++)
//	//	{
//	//		if (matrix[i][i] == 0)
//	//			is_ok = true;
//	//	}
//	//	return  is_ok;
//	//};
//	//while (true)
//	//{
//	//	int i = 0;
//	//	for (; i < width - 1; i++)
//	//	{
//	//		if (matrix[i][i] == 0)
//	//		{
//	//			for (int j = i; j < height; j++)
//	//			{
//	//				if (j == i) continue;
//	//				if (matrix[j][i] != 0 && matrix[i][j] != 0)
//	//				{
//	//					swap<std::vector<double>>(matrix[i], matrix[j]);
//	//					break;
//	//				}
//	//			}
//	//		}
//	//	}
//	//	if (a() == false)
//	//		break;
//	//}
//	////std::vector<int>    max_index;
//	////std::vector<int>    max_value;
//	////std::vector<int>    none_zero;
//
//	//////���м���Ϊ0ʱ���޷����㣬����Ҫ��֤�м��Ϊ0
//	////for (int i = 0; i < width - 1; i++)
//	////{
//	////	//int k = 0;
//	////	//while (matrix[i][i] == 0 && k < (width - 1)*height)
//	////	//{
//	////	//	for (int j = 0; j < height ; j++) 
//	////	//	{
//	////	//		if (j == i) continue;
//	////	//		if (matrix[j][i] != 0 /*&& matrix[i][j] != 0*/)
//	////	//		{
//	////	//			swap<std::vector<double>>(matrix[i], matrix[j]);
//	////	//			break;
//	////	//		}
//	////	//	}
//	////	//	k++;
//	////	//}
//	////	//if (matrix[i][i] == 0) return false;
//	//////ѡ��Ԫ[��һ�еľ���ֵ���ֵ]
//	////	double ab_max = 0;
//	////	int index = -1;
//	////	int none = 0;
//	////	for (int j = 0; j < height; j++)
//	////	{
//	////		if (abs(matrix[i][j]) > ab_max);
//	////		{
//	////			ab_max = abs(matrix[i][j]);
//	////			index = j;
//	////			none++;
//	////		}
//	////	}
//	////	if (index != -1)
//	////	{
//	////		max_index.push_back(index);
//	////		max_value.push_back(ab_max);
//	////		none_zero.push_back(none);
//	////	}
//	////	else
//	////		return false;
//	////}
//
//
//	////for (int i = 0; i < max_index.size() -1; i++)
//	////{
//	////	for (int j = i + 1; j < max_index.size(); j++)
//	////	{
//	////		if (max_index[i] == max_index[j])
//	////		{
//	////			auto function = [&]()
//	////			{
//	////				double ab_max = 0;
//	////				int index = -1;
//	////				for (int n = 0; n < height; n++)
//	////				{
//	////					if (abs(matrix[i][n]) > ab_max && abs(matrix[i][n]) < max_value[i]);
//	////					{
//	////						ab_max = abs(matrix[i][n]);
//	////						index = j;
//	////					}
//	////				}
//	////				max_index[i] = index;
//	////				max_value[i] = ab_max;
//	////			};
//	////			if (none_zero[j] != 1)
//	////			{
//	////				function();
//	////			}
//	////			else if (none_zero[i] != 1)
//	////			{
//	////				function();
//	////			}
//	////			else
//	////			{
//	////				return false;
//	////			}
//	////		}
//	////	}
//	////}
//	//
//
//	////ѭ������
//	//for (int i = 0; i < width - 2; i++)
//	//{
//	//	for (int j = i+1; j < height; j++)
//	//	{
//	//		if (matrix[j][i] != 0)
//	//		{
//	//			int temp_value = matrix[j][i];
//	//			for (int k = 0; k < width; k++)
//	//			{
//	//				matrix[j][k] = matrix[j][k] / temp_value * matrix[i][i] - matrix[i][k];;
//	//			}
//	//		}
//
//	//	}
//	//}
//
//
//
//
//	////������-1 ����
//	//for (int i = 0; i < width - 1; i++)
//	//{
//	//	if (matrix[i][i] == 0)
//	//	{
//
//	//	}
//	//}
//	////if (width - 1 > height)
//	////{
//	////	return false;
//	////}
//	//////����-1����ȥ���������õľ���
//	////else if (width - 1 < height)
//	////{
//	////	//����������������ʱ���ܻ���֣�ĳ������ȫһ����������ȫΪ0
//	////	//��Ϊ����������ǵ㣬���������������ȫһ�������Դ�ѭ���������͸�Ӻͷ�����ûʲô���á�
//	////	for (int i = 0; i < width - 1; i++)
//	////	{
//	////		if (matrix[i][i] == 0)
//	////		{
//	////			for (int j = 0; j < height; j++)
//	////			{
//	////				if (j == i) continue;
//	////				if (matrix[j][i] != 0 /*&& matrix[i][j] != 0*/)
//	////				{
//	////					swap<std::vector<double>>(matrix[i], matrix[j]);
//	////					break;
//	////				}
//	////			}
//	////		}
//	////		if (matrix[i][i] == 0) return false;
//	////	}
//	////	for (int i = width - 1; i != height; )
//	////	{
//	////		matrix.pop_back();
//	////		height--;
//	////	}
//	////}
//
//
//	////ѭ������
//	//for (int i = width - 2; i > -1; i--)
//	//{
//	//	for (int j = i-1; j >-1; j--)
//	//	{
//	//		if (matrix[j][i] != 0)
//	//		{
//	//			double temp_value = matrix[j][i];
//	//			for (int k = 0; k < width; k++)
//	//			{
//	//				matrix[j][k] = matrix[j][k] / temp_value * matrix[i][i] - matrix[i][k];
//	//			}
//	//		}
//	//	}
//	//}
//
//	////������
//	//for (int i = 0; i <  height; i++)
//	//{
//	//	if (matrix[i][i] == 0)
//	//		return false;
//	//	output_matrix.push_back(matrix[i][height] / matrix[i][i]);
//	//}
//	//return true;
//}
//




