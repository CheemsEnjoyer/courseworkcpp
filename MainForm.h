#pragma once
#include "AddPatientForm.h"
#include "ChronicPatients.h"
#include "RedactForm.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <cstdint>
#include "Curtain.h"
namespace hospital {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace hospital;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;
	using namespace System::Threading;
	struct PatientInfo {
		char Number[10];
		char Name[50];
		char DateOfBirth[15];
		char PatientID[50];
		char illness[50];
		char Doctor[50];
		char DateOfVisit[15];
	};
	std::vector<PatientInfo> data;
	/// <summary>
	/// ������ ��� MainForm
	/// </summary>	
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			isModified = false;
			dataGridView1->ContextMenuStrip = contextMenuStrip1;
			std::string currentFileName;
			Thread^ t = gcnew Thread(gcnew ThreadStart(this, &MainForm	::StartForm));
			t->Start();
			Thread::Sleep(1500);
			t->Abort();
		}
		void StartForm()
		{
			hospital::Curtain form;
			Application::Run(% form);
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rdctToolStripMenuItem;
	protected:


	private: System::Windows::Forms::ToolStripMenuItem^ SearchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AboutProgrammToolStripMenuItem;






	private: System::Windows::Forms::DataGridView^ dataGridView1;








	private: System::Windows::Forms::DataVisualization::Charting::Chart^ illnesschart;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ DoctorChart;


	private: System::Windows::Forms::ToolStripMenuItem^ SaveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ SaveToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ DownloadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addToolStripMenuItem1;


	private: System::Windows::Forms::ToolStripMenuItem^ DeletePatientToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ SortToolStripMenuItem;




	private: System::Windows::Forms::Button^ searchButton;
	private: System::Windows::Forms::TextBox^ searchTextBox;










	private: System::Windows::Forms::ToolStripMenuItem^ CloseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ RecentFirstToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ OldOnesFirstToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ srchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ChronPatientsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AboutProgToolStripMenuItem;



	private: System::Windows::Forms::ToolStripMenuItem^ referenceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ TaskToolStripMenuItem1;



	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ Copy;
	private: System::Windows::Forms::ToolStripMenuItem^ Cut;
	private: System::Windows::Forms::ToolStripMenuItem^ Input;
	private: System::Windows::Forms::ToolStripMenuItem^ Delete;
	private: System::Windows::Forms::ToolStripMenuItem^ RedactToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ illnessToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ illnessAscendingToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ illnessDescendingToolStripMenuItem1;



	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ DoctorAscendingToolStripMenuItem2;
private: System::Windows::Forms::ToolStripMenuItem^ DoctorDescendingToolStripMenuItem2;
private: System::Windows::Forms::ToolStripMenuItem^ ������������ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ dataAnalysToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ DiagnosisStatisticToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ DoctorPressureToolStripMenuItem;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ DateOfBirth;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ PatientID;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ illness;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Doctor;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ DateOfVisit;
private: System::Windows::Forms::ToolStrip^ toolStrip1;
private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
private: System::Windows::Forms::ToolStripButton^ toolStripButton5;
private: System::Windows::Forms::ToolStripButton^ toolStripButton6;
private: System::Windows::Forms::ToolStripButton^ toolStripButton7;
private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton1;
private: System::Windows::Forms::ToolStripMenuItem^ ������������������ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton2;
private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;





































	private: System::ComponentModel::IContainer^ components;







	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DownloadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CloseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rdctToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RedactToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DeletePatientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->illnessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->illnessAscendingToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->illnessDescendingToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DoctorAscendingToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DoctorDescendingToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RecentFirstToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OldOnesFirstToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SearchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->srchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ChronPatientsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataAnalysToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DiagnosisStatisticToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DoctorPressureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AboutProgrammToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AboutProgToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->referenceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TaskToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DateOfBirth = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PatientID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->illness = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Doctor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DateOfVisit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->illnesschart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->DoctorChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->Copy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Cut = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Input = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Delete = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripDropDownButton2 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->illnesschart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DoctorChart))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Control;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->rdctToolStripMenuItem, this->SearchToolStripMenuItem, this->dataAnalysToolStripMenuItem, this->AboutProgrammToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->DownloadToolStripMenuItem,
					this->SaveToolStripMenuItem, this->SaveAsToolStripMenuItem, this->CloseToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->fileToolStripMenuItem->Text = L"����";
			// 
			// DownloadToolStripMenuItem
			// 
			this->DownloadToolStripMenuItem->Name = L"DownloadToolStripMenuItem";
			this->DownloadToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::O));
			this->DownloadToolStripMenuItem->Size = System::Drawing::Size(274, 26);
			this->DownloadToolStripMenuItem->Text = L"�������";
			this->DownloadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::DownloadToolStripMenuItem_Click);
			// 
			// SaveToolStripMenuItem
			// 
			this->SaveToolStripMenuItem->Enabled = false;
			this->SaveToolStripMenuItem->Name = L"SaveToolStripMenuItem";
			this->SaveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->SaveToolStripMenuItem->Size = System::Drawing::Size(274, 26);
			this->SaveToolStripMenuItem->Text = L"���������";
			this->SaveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SaveAsToolStripMenuItem_Click);
			// 
			// SaveAsToolStripMenuItem
			// 
			this->SaveAsToolStripMenuItem->Enabled = false;
			this->SaveAsToolStripMenuItem->Name = L"SaveAsToolStripMenuItem";
			this->SaveAsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->SaveAsToolStripMenuItem->Size = System::Drawing::Size(274, 26);
			this->SaveAsToolStripMenuItem->Text = L"��������� ���";
			this->SaveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SaveToolStripMenuItem_Click);
			// 
			// CloseToolStripMenuItem
			// 
			this->CloseToolStripMenuItem->Name = L"CloseToolStripMenuItem";
			this->CloseToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->CloseToolStripMenuItem->Size = System::Drawing::Size(274, 26);
			this->CloseToolStripMenuItem->Text = L"�������";
			this->CloseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::CloseToolStripMenuItem_Click);
			// 
			// rdctToolStripMenuItem
			// 
			this->rdctToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->addToolStripMenuItem1,
					this->RedactToolStripMenuItem1, this->DeletePatientToolStripMenuItem, this->SortToolStripMenuItem
			});
			this->rdctToolStripMenuItem->Name = L"rdctToolStripMenuItem";
			this->rdctToolStripMenuItem->Size = System::Drawing::Size(125, 24);
			this->rdctToolStripMenuItem->Text = L"�������������";
			// 
			// addToolStripMenuItem1
			// 
			this->addToolStripMenuItem1->Name = L"addToolStripMenuItem1";
			this->addToolStripMenuItem1->Size = System::Drawing::Size(207, 26);
			this->addToolStripMenuItem1->Text = L"��������";
			this->addToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::AddPatientToolStripMenuItem_Click);
			// 
			// RedactToolStripMenuItem1
			// 
			this->RedactToolStripMenuItem1->Enabled = false;
			this->RedactToolStripMenuItem1->Name = L"RedactToolStripMenuItem1";
			this->RedactToolStripMenuItem1->Size = System::Drawing::Size(207, 26);
			this->RedactToolStripMenuItem1->Text = L"�������������";
			this->RedactToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::�������������ToolStripMenuItem_Click);
			// 
			// DeletePatientToolStripMenuItem
			// 
			this->DeletePatientToolStripMenuItem->Enabled = false;
			this->DeletePatientToolStripMenuItem->Name = L"DeletePatientToolStripMenuItem";
			this->DeletePatientToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::Delete;
			this->DeletePatientToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->DeletePatientToolStripMenuItem->Text = L"�������";
			this->DeletePatientToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::DeletePatientToolStripMenuItem_Click);
			// 
			// SortToolStripMenuItem
			// 
			this->SortToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->�����ToolStripMenuItem,
					this->���ToolStripMenuItem, this->������������ToolStripMenuItem, this->illnessToolStripMenuItem, this->����ToolStripMenuItem,
					this->�������������ToolStripMenuItem
			});
			this->SortToolStripMenuItem->Enabled = false;
			this->SortToolStripMenuItem->Name = L"SortToolStripMenuItem";
			this->SortToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->SortToolStripMenuItem->Text = L"�����������";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������������ToolStripMenuItem,
					this->��ToolStripMenuItem
			});
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->�����ToolStripMenuItem->Text = L"�����";
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(208, 26);
			this->�������������ToolStripMenuItem->Text = L"�� �����������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::Accending�����ToolStripMenuItem_Click);
			// 
			// ��ToolStripMenuItem
			// 
			this->��ToolStripMenuItem->Name = L"��ToolStripMenuItem";
			this->��ToolStripMenuItem->Size = System::Drawing::Size(208, 26);
			this->��ToolStripMenuItem->Text = L"�� ��������";
			this->��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::DescendingToolStripMenuItem_Click);
			// 
			// ���ToolStripMenuItem
			// 
			this->���ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->������ToolStripMenuItem,
					this->������ToolStripMenuItem
			});
			this->���ToolStripMenuItem->Name = L"���ToolStripMenuItem";
			this->���ToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->���ToolStripMenuItem->Text = L"�.�.�";
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(157, 26);
			this->������ToolStripMenuItem->Text = L"�� � �� �";
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::FromFirstToLastToolStripMenuItem_Click);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(157, 26);
			this->������ToolStripMenuItem->Text = L"�� � �� �";
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::FromLastToFirstToolStripMenuItem_Click);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��������������ToolStripMenuItem,
					this->�������������ToolStripMenuItem
			});
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->������������ToolStripMenuItem->Text = L"���� ��������";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->��������������ToolStripMenuItem->Text = L"�� ����� �������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::YoungGoFirstToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->�������������ToolStripMenuItem->Text = L"�� ����� ������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::OldGoFirstToolStripMenuItem_Click);
			// 
			// illnessToolStripMenuItem
			// 
			this->illnessToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->illnessAscendingToolStripMenuItem1,
					this->illnessDescendingToolStripMenuItem1
			});
			this->illnessToolStripMenuItem->Name = L"illnessToolStripMenuItem";
			this->illnessToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->illnessToolStripMenuItem->Text = L"�������";
			// 
			// illnessAscendingToolStripMenuItem1
			// 
			this->illnessAscendingToolStripMenuItem1->Name = L"illnessAscendingToolStripMenuItem1";
			this->illnessAscendingToolStripMenuItem1->Size = System::Drawing::Size(157, 26);
			this->illnessAscendingToolStripMenuItem1->Text = L"�� � �� �";
			this->illnessAscendingToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::illnessAscendingToolStripMenuItem1_Click);
			// 
			// illnessDescendingToolStripMenuItem1
			// 
			this->illnessDescendingToolStripMenuItem1->Name = L"illnessDescendingToolStripMenuItem1";
			this->illnessDescendingToolStripMenuItem1->Size = System::Drawing::Size(157, 26);
			this->illnessDescendingToolStripMenuItem1->Text = L"�� � �� �";
			this->illnessDescendingToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::illnessDescendingToolStripMenuItem1_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->DoctorAscendingToolStripMenuItem2,
					this->DoctorDescendingToolStripMenuItem2
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// DoctorAscendingToolStripMenuItem2
			// 
			this->DoctorAscendingToolStripMenuItem2->Name = L"DoctorAscendingToolStripMenuItem2";
			this->DoctorAscendingToolStripMenuItem2->Size = System::Drawing::Size(157, 26);
			this->DoctorAscendingToolStripMenuItem2->Text = L"�� � �� �";
			this->DoctorAscendingToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::DoctorAscendingToolStripMenuItem2_Click);
			// 
			// DoctorDescendingToolStripMenuItem2
			// 
			this->DoctorDescendingToolStripMenuItem2->Name = L"DoctorDescendingToolStripMenuItem2";
			this->DoctorDescendingToolStripMenuItem2->Size = System::Drawing::Size(157, 26);
			this->DoctorDescendingToolStripMenuItem2->Text = L"�� � �� �";
			this->DoctorDescendingToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::DoctorDescendingToolStripMenuItem2_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->RecentFirstToolStripMenuItem,
					this->OldOnesFirstToolStripMenuItem
			});
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->�������������ToolStripMenuItem->Text = L"���� ���������";
			// 
			// RecentFirstToolStripMenuItem
			// 
			this->RecentFirstToolStripMenuItem->Name = L"RecentFirstToolStripMenuItem";
			this->RecentFirstToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->RecentFirstToolStripMenuItem->Text = L"�� ����� ��������";
			this->RecentFirstToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::RecentFirstToolStripMenuItem_Click);
			// 
			// OldOnesFirstToolStripMenuItem
			// 
			this->OldOnesFirstToolStripMenuItem->Name = L"OldOnesFirstToolStripMenuItem";
			this->OldOnesFirstToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->OldOnesFirstToolStripMenuItem->Text = L"�� ����� ������";
			this->OldOnesFirstToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::OldOnesFirstToolStripMenuItem_Click);
			// 
			// SearchToolStripMenuItem
			// 
			this->SearchToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->srchToolStripMenuItem,
					this->ChronPatientsToolStripMenuItem
			});
			this->SearchToolStripMenuItem->Name = L"SearchToolStripMenuItem";
			this->SearchToolStripMenuItem->Size = System::Drawing::Size(66, 24);
			this->SearchToolStripMenuItem->Text = L"�����";
			// 
			// srchToolStripMenuItem
			// 
			this->srchToolStripMenuItem->Name = L"srchToolStripMenuItem";
			this->srchToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->srchToolStripMenuItem->Size = System::Drawing::Size(395, 26);
			this->srchToolStripMenuItem->Text = L"�����";
			this->srchToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SearchToolStripMenuItem_Click);
			// 
			// ChronPatientsToolStripMenuItem
			// 
			this->ChronPatientsToolStripMenuItem->Enabled = false;
			this->ChronPatientsToolStripMenuItem->Name = L"ChronPatientsToolStripMenuItem";
			this->ChronPatientsToolStripMenuItem->Size = System::Drawing::Size(395, 26);
			this->ChronPatientsToolStripMenuItem->Text = L"�������� � ������������ �������������";
			this->ChronPatientsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ChronPatientsButtonToolStripMenuItem_Click);
			// 
			// dataAnalysToolStripMenuItem
			// 
			this->dataAnalysToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->DiagnosisStatisticToolStripMenuItem,
					this->DoctorPressureToolStripMenuItem
			});
			this->dataAnalysToolStripMenuItem->Name = L"dataAnalysToolStripMenuItem";
			this->dataAnalysToolStripMenuItem->Size = System::Drawing::Size(130, 24);
			this->dataAnalysToolStripMenuItem->Text = L"������ ������";
			// 
			// DiagnosisStatisticToolStripMenuItem
			// 
			this->DiagnosisStatisticToolStripMenuItem->Enabled = false;
			this->DiagnosisStatisticToolStripMenuItem->Name = L"DiagnosisStatisticToolStripMenuItem";
			this->DiagnosisStatisticToolStripMenuItem->Size = System::Drawing::Size(238, 26);
			this->DiagnosisStatisticToolStripMenuItem->Text = L"���������� ��������";
			this->DiagnosisStatisticToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::DiagnosisStatisticToolStripMenuItem_Click);
			// 
			// DoctorPressureToolStripMenuItem
			// 
			this->DoctorPressureToolStripMenuItem->Enabled = false;
			this->DoctorPressureToolStripMenuItem->Name = L"DoctorPressureToolStripMenuItem";
			this->DoctorPressureToolStripMenuItem->Size = System::Drawing::Size(238, 26);
			this->DoctorPressureToolStripMenuItem->Text = L"�������� ������";
			this->DoctorPressureToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::DoctorPressureToolStripMenuItem_Click);
			// 
			// AboutProgrammToolStripMenuItem
			// 
			this->AboutProgrammToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->AboutProgToolStripMenuItem,
					this->referenceToolStripMenuItem, this->TaskToolStripMenuItem1
			});
			this->AboutProgrammToolStripMenuItem->Name = L"AboutProgrammToolStripMenuItem";
			this->AboutProgrammToolStripMenuItem->Size = System::Drawing::Size(118, 24);
			this->AboutProgrammToolStripMenuItem->Text = L"� ���������";
			// 
			// AboutProgToolStripMenuItem
			// 
			this->AboutProgToolStripMenuItem->Name = L"AboutProgToolStripMenuItem";
			this->AboutProgToolStripMenuItem->Size = System::Drawing::Size(187, 26);
			this->AboutProgToolStripMenuItem->Text = L"� ���������";
			this->AboutProgToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::AboutProgrammToolStripMenuItem_Click);
			// 
			// referenceToolStripMenuItem
			// 
			this->referenceToolStripMenuItem->Name = L"referenceToolStripMenuItem";
			this->referenceToolStripMenuItem->Size = System::Drawing::Size(187, 26);
			this->referenceToolStripMenuItem->Text = L"�������";
			this->referenceToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GuideToolStripMenuItem_Click);
			// 
			// TaskToolStripMenuItem1
			// 
			this->TaskToolStripMenuItem1->Name = L"TaskToolStripMenuItem1";
			this->TaskToolStripMenuItem1->Size = System::Drawing::Size(187, 26);
			this->TaskToolStripMenuItem1->Text = L"�������";
			this->TaskToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::AboutTaskToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Number,
					this->Name, this->DateOfBirth, this->PatientID, this->illness, this->Doctor, this->DateOfVisit
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView1->Location = System::Drawing::Point(0, 58);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1924, 923);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellValueChanged);
			this->dataGridView1->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MainForm::dataGridView_RowsAdded);
			// 
			// Number
			// 
			this->Number->HeaderText = L"�����";
			this->Number->MinimumWidth = 6;
			this->Number->Name = L"Number";
			this->Number->Width = 125;
			// 
			// Name
			// 
			this->Name->HeaderText = L"�.�.�";
			this->Name->MinimumWidth = 6;
			this->Name->Name = L"Name";
			this->Name->Width = 125;
			// 
			// DateOfBirth
			// 
			dataGridViewCellStyle2->Format = L"d";
			dataGridViewCellStyle2->NullValue = nullptr;
			this->DateOfBirth->DefaultCellStyle = dataGridViewCellStyle2;
			this->DateOfBirth->HeaderText = L"���� ��������";
			this->DateOfBirth->MaxInputLength = 10;
			this->DateOfBirth->MinimumWidth = 6;
			this->DateOfBirth->Name = L"DateOfBirth";
			this->DateOfBirth->Width = 125;
			// 
			// PatientID
			// 
			this->PatientID->HeaderText = L"����� ������";
			this->PatientID->MinimumWidth = 6;
			this->PatientID->Name = L"PatientID";
			this->PatientID->Width = 125;
			// 
			// illness
			// 
			this->illness->HeaderText = L"�������";
			this->illness->MinimumWidth = 6;
			this->illness->Name = L"illness";
			this->illness->Width = 125;
			// 
			// Doctor
			// 
			this->Doctor->HeaderText = L"����";
			this->Doctor->MinimumWidth = 6;
			this->Doctor->Name = L"Doctor";
			this->Doctor->Width = 125;
			// 
			// DateOfVisit
			// 
			dataGridViewCellStyle3->Format = L"d";
			dataGridViewCellStyle3->NullValue = nullptr;
			this->DateOfVisit->DefaultCellStyle = dataGridViewCellStyle3;
			this->DateOfVisit->HeaderText = L"���� ���������";
			this->DateOfVisit->MinimumWidth = 6;
			this->DateOfVisit->Name = L"DateOfVisit";
			this->DateOfVisit->Width = 125;
			// 
			// illnesschart
			// 
			chartArea1->Name = L"ChartArea1";
			this->illnesschart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			legend1->Title = L"���������� ��������";
			legend1->TitleFont = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->illnesschart->Legends->Add(legend1);
			this->illnesschart->Location = System::Drawing::Point(1261, 204);
			this->illnesschart->Name = L"illnesschart";
			series1->ChartArea = L"ChartArea1";
			series1->IsVisibleInLegend = false;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->illnesschart->Series->Add(series1);
			this->illnesschart->Size = System::Drawing::Size(416, 379);
			this->illnesschart->TabIndex = 2;
			this->illnesschart->Text = L"chart1";
			this->illnesschart->Visible = false;
			// 
			// DoctorChart
			// 
			chartArea2->Name = L"ChartArea1";
			this->DoctorChart->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			legend2->Title = L"�������� ������";
			legend2->TitleFont = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DoctorChart->Legends->Add(legend2);
			this->DoctorChart->Location = System::Drawing::Point(1261, 204);
			this->DoctorChart->Name = L"DoctorChart";
			series2->ChartArea = L"ChartArea1";
			series2->IsVisibleInLegend = false;
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->DoctorChart->Series->Add(series2);
			this->DoctorChart->Size = System::Drawing::Size(370, 364);
			this->DoctorChart->TabIndex = 4;
			this->DoctorChart->Text = L"chart1";
			this->DoctorChart->Visible = false;
			// 
			// searchButton
			// 
			this->searchButton->Location = System::Drawing::Point(1362, 159);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(87, 23);
			this->searchButton->TabIndex = 7;
			this->searchButton->Text = L"������";
			this->searchButton->UseVisualStyleBackColor = true;
			this->searchButton->Visible = false;
			this->searchButton->Click += gcnew System::EventHandler(this, &MainForm::searchButton_Click);
			// 
			// searchTextBox
			// 
			this->searchTextBox->Location = System::Drawing::Point(1244, 121);
			this->searchTextBox->Name = L"searchTextBox";
			this->searchTextBox->Size = System::Drawing::Size(205, 22);
			this->searchTextBox->TabIndex = 8;
			this->searchTextBox->Visible = false;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->Copy, this->Cut,
					this->Input, this->Delete, this->�������������ToolStripMenuItem1
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(181, 124);
			this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::contextMenuStrip1_Opening_1);
			// 
			// Copy
			// 
			this->Copy->Name = L"Copy";
			this->Copy->Size = System::Drawing::Size(180, 24);
			this->Copy->Text = L"����������";
			this->Copy->Click += gcnew System::EventHandler(this, &MainForm::Copy_Click);
			// 
			// Cut
			// 
			this->Cut->Name = L"Cut";
			this->Cut->Size = System::Drawing::Size(180, 24);
			this->Cut->Text = L"��������";
			this->Cut->Click += gcnew System::EventHandler(this, &MainForm::Cut_Click);
			// 
			// Input
			// 
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(180, 24);
			this->Input->Text = L"��������";
			this->Input->Click += gcnew System::EventHandler(this, &MainForm::Input_Click);
			// 
			// Delete
			// 
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(180, 24);
			this->Delete->Text = L"�������";
			this->Delete->Click += gcnew System::EventHandler(this, &MainForm::Delete_Click);
			// 
			// �������������ToolStripMenuItem1
			// 
			this->�������������ToolStripMenuItem1->Name = L"�������������ToolStripMenuItem1";
			this->�������������ToolStripMenuItem1->Size = System::Drawing::Size(180, 24);
			this->�������������ToolStripMenuItem1->Text = L"�������������";
			this->�������������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::�������������ToolStripMenuItem1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1420, 185);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 16);
			this->label1->TabIndex = 9;
			this->label1->Text = L"���������� ��������";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1420, 185);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 16);
			this->label2->TabIndex = 10;
			this->label2->Text = L"�������� ������";
			this->label2->Visible = false;
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->toolStripButton1,
					this->toolStripButton2, this->toolStripButton3, this->toolStripButton4, this->toolStripButton5, this->toolStripButton6, this->toolStripButton7,
					this->toolStripDropDownButton1, this->toolStripDropDownButton2
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 28);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1924, 27);
			this->toolStrip1->TabIndex = 11;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Enabled = false;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(29, 24);
			this->toolStripButton1->Text = L"���������";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton1_Click);
			this->toolStripButton1->MouseHover += gcnew System::EventHandler(this, &MainForm::toolStripButton1_MouseHover);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(29, 24);
			this->toolStripButton2->Text = L"�������";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton2_Click);
			this->toolStripButton2->MouseHover += gcnew System::EventHandler(this, &MainForm::toolStripButton2_MouseHover);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(29, 24);
			this->toolStripButton3->Text = L"�������� ��������";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton3_Click);
			this->toolStripButton3->MouseHover += gcnew System::EventHandler(this, &MainForm::toolStripButton3_MouseHover);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Enabled = false;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(29, 24);
			this->toolStripButton4->Text = L"�������������";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton4_Click);
			this->toolStripButton4->MouseHover += gcnew System::EventHandler(this, &MainForm::toolStripButton4_MouseHover);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton5->Enabled = false;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(29, 24);
			this->toolStripButton5->Text = L"�������";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton5_Click);
			this->toolStripButton5->MouseHover += gcnew System::EventHandler(this, &MainForm::toolStripButton5_MouseHover);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton6->Enabled = false;
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(29, 24);
			this->toolStripButton6->Text = L"�����";
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton6_Click);
			this->toolStripButton6->MouseHover += gcnew System::EventHandler(this, &MainForm::toolStripButton6_MouseHover);
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton7->Enabled = false;
			this->toolStripButton7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton7.Image")));
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(29, 24);
			this->toolStripButton7->Text = L"�������� � ������������ �������������";
			this->toolStripButton7->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton7_Click);
			this->toolStripButton7->MouseHover += gcnew System::EventHandler(this, &MainForm::toolStripButton7_MouseHover);
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->������������������ToolStripMenuItem,
					this->��������������ToolStripMenuItem
			});
			this->toolStripDropDownButton1->Enabled = false;
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(34, 24);
			this->toolStripDropDownButton1->Text = L"����������";
			this->toolStripDropDownButton1->MouseHover += gcnew System::EventHandler(this, &MainForm::toolStripDropDownButton1_MouseHover);
			// 
			// ������������������ToolStripMenuItem
			// 
			this->������������������ToolStripMenuItem->Name = L"������������������ToolStripMenuItem";
			this->������������������ToolStripMenuItem->Size = System::Drawing::Size(238, 26);
			this->������������������ToolStripMenuItem->Text = L"���������� ��������";
			this->������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::������������������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(238, 26);
			this->��������������ToolStripMenuItem->Text = L"�������� ������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::��������������ToolStripMenuItem_Click);
			// 
			// toolStripDropDownButton2
			// 
			this->toolStripDropDownButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����������ToolStripMenuItem,
					this->���������ToolStripMenuItem, this->�������ToolStripMenuItem
			});
			this->toolStripDropDownButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton2.Image")));
			this->toolStripDropDownButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton2->Name = L"toolStripDropDownButton2";
			this->toolStripDropDownButton2->Size = System::Drawing::Size(34, 24);
			this->toolStripDropDownButton2->Text = L"� ���������";
			this->toolStripDropDownButton2->MouseHover += gcnew System::EventHandler(this, &MainForm::toolStripDropDownButton2_MouseHover);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::����������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->���������ToolStripMenuItem->Text = L"�������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�������ToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1924, 993);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->searchTextBox);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->DoctorChart);
			this->Controls->Add(this->illnesschart);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Text = L"�����������";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->illnesschart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DoctorChart))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void AddPatientToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ������� ��� �������� ����� ����� ������ � DataGridView
		AddPatientForm^ addPatient = gcnew AddPatientForm;
		addPatient->Show();
		addPatient->Visible = false;
		if (addPatient->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			dataGridView1->Rows->Add(addPatient->InputValues);
		}
		else {
			MessageBox::Show("������� �� ��� ��������", "���������� ��������", MessageBoxButtons::OK);
		}
	}
	private: System::Void AboutTaskToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ������� ��� �������� MessageBox, � ������� ������� ���������� ������
		MessageBox::Show("�������� ���������, �������������� ��������� �������� � ����������� ����������� : �.�.�., ���� ��������, ����� ������, �������, �.�.�.�������� �����, ���� ���������. "
			"���������� �������� ������� �����, ������ ���������� �� ������������(� ���� ���������), ������������ ������ ���������, ���������� ������������ �������������(�.�.������������ � ����� ����� 3 ��� � ������� ���� � ����� � ��� �� ���������)",
			"� ������� ", MessageBoxButtons::OK);
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void RefreshChartData_Click(System::Object^ sender, System::EventArgs^ e) { // ������� ��� ���� ������ �� DataGridView � ��������� �� ������� �� ������
		// ������� ������ � Chart
		this->illnesschart->Series["Series1"]->Points->Clear();
		this->DoctorChart->Series["Series1"]->Points->Clear();
		// ������� ������� ��� �������� ���������� ������ �������
		Dictionary<String^, int>^ illnessCounts = gcnew Dictionary<String^, int>();

		Dictionary<String^, int>^ doctorPressure = gcnew Dictionary<String^, int>();
		// �������� ���������� ����� � DataGridView
		int rowCount = dataGridView1->RowCount;

		// ������������ ���������� ������ �������
		for (int i = 0; i < rowCount; i++) {
			String^ illness = dataGridView1->Rows[i]->Cells[4]->Value->ToString();
			if (illnessCounts->ContainsKey(illness)) {
				illnessCounts[illness]++;
			}
			else {
				illnessCounts[illness] = 1;
			}
		}
		for (int i = 0; i < rowCount; i++) {
			String^ doctor = dataGridView1->Rows[i]->Cells[5]->Value->ToString();
			if (doctorPressure->ContainsKey(doctor)) {
				doctorPressure[doctor]++;
			}
			else {
				doctorPressure[doctor] = 1;
			}
		}
		// ��������� ������ � Chart
		for each (KeyValuePair<String^, int> ^ pair in illnessCounts) {
			this->illnesschart->Series["Series1"]->Points->AddXY(pair->Key, pair->Value);
		}
		for each (KeyValuePair<String^, int> ^ pair in doctorPressure) {
			this->DoctorChart->Series["Series1"]->Points->AddXY(pair->Key, pair->Value);
		}
		// ������������� �������� ��� ��� Y ������ 1
		this->illnesschart->ChartAreas[0]->AxisY->Interval = 1;
		this->DoctorChart->ChartAreas[0]->AxisY->Interval = 1;
	}


private: System::Void DownloadToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ������� �������� ������ �� ��������� �����
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Title = "Open binary file";
	openFileDialog->Filter = "Binary files (*.bin)|*.bin";
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ fileName = openFileDialog->FileName;
		currentFileName = fileName;
		FileStream^ fs = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
		BinaryReader^ br = gcnew BinaryReader(fs);

		// �������� ������ �� ��������� ����� � DataGridView
		int i = 0;
		dataGridView1->Rows->Clear();
		while (br->PeekChar() != -1)
		{
			PatientInfo patient;

			// ������ ������ ��������� PatientInfo �� ��������� �����
			array<Byte>^ numberBytes = br->ReadBytes(sizeof(patient.Number));
			pin_ptr<unsigned char> numberPinPtr = &numberBytes[0];
			memcpy_s(patient.Number, sizeof(patient.Number), numberPinPtr, sizeof(patient.Number));

			array<Byte>^ nameBytes = br->ReadBytes(sizeof(patient.Name));
			if (nameBytes->Length > 0)
			{
			pin_ptr<unsigned char> namePinPtr = &nameBytes[0];
			memcpy_s(patient.Name, sizeof(patient.Name), namePinPtr, sizeof(patient.Name));
			}

			array<Byte>^ DateOfBirthBytes = br->ReadBytes(sizeof(patient.DateOfBirth));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> DateOfBirthPinPtr = &DateOfBirthBytes[0];
				memcpy_s(patient.DateOfBirth, sizeof(patient.DateOfBirth), DateOfBirthPinPtr, sizeof(patient.DateOfBirth));
			}

			array<Byte>^ PatientIDBytes = br->ReadBytes(sizeof(patient.PatientID));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> PatientIDPinPtr = &PatientIDBytes[0];
				memcpy_s(patient.PatientID, sizeof(patient.PatientID), PatientIDPinPtr, sizeof(patient.PatientID));
			}

			array<Byte>^ illnessBytes = br->ReadBytes(sizeof(patient.illness));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> illnessPinPtr = &illnessBytes[0];
				memcpy_s(patient.illness, sizeof(patient.illness), illnessPinPtr, sizeof(patient.illness));
			}
			array<Byte>^ DoctorBytes = br->ReadBytes(sizeof(patient.Doctor));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> DoctorPinPtr = &DoctorBytes[0];
				memcpy_s(patient.Doctor, sizeof(patient.Doctor), DoctorPinPtr, sizeof(patient.Doctor));
			}

			array<Byte>^ DateOfVisitBytes = br->ReadBytes(sizeof(patient.DateOfVisit));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> DateOfVisitPinPtr = &DateOfVisitBytes[0];
				memcpy_s(patient.DateOfVisit, sizeof(patient.DateOfVisit), DateOfVisitPinPtr, sizeof(patient.DateOfVisit));
			}
			// ���������� ������ � DataGridView
			array<String^>^ row = gcnew array<String^>{
				gcnew String(patient.Number),
					gcnew String(patient.Name),
						gcnew String(patient.DateOfBirth),
							gcnew String(patient.PatientID),
								gcnew String(patient.illness),
									gcnew String(patient.Doctor),
										gcnew String(patient.DateOfVisit)
					// ����������� ��� ��������� ����� ��������� PatientInfo
			};

			dataGridView1->Rows->Add(row);
		}
		br->Close();
		fs->Close();
	}
};
private:
	bool isModified = false;
private:
	bool isDataSaved;
private: System::Void dataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	isModified = true;
	isDataSaved = false;
	if (dataGridView1->Rows->Count == 0) {
		SaveToolStripMenuItem->Enabled = false;
		SaveAsToolStripMenuItem->Enabled = false;
		RedactToolStripMenuItem1->Enabled = false;
		DeletePatientToolStripMenuItem->Enabled = false;
		SortToolStripMenuItem->Enabled = false;
		ChronPatientsToolStripMenuItem->Enabled = false;
		DiagnosisStatisticToolStripMenuItem->Enabled = false;
		DoctorPressureToolStripMenuItem->Enabled = false;
		toolStripButton1->Enabled = false;
		toolStripButton4->Enabled = false;
		toolStripButton5->Enabled = false;
		toolStripButton6->Enabled = false;
		toolStripButton7->Enabled = false;
		toolStripDropDownButton1->Enabled = false;
	}
	else {
		SaveToolStripMenuItem->Enabled = true;
		SaveAsToolStripMenuItem->Enabled = true;
		RedactToolStripMenuItem1->Enabled = true;
		DeletePatientToolStripMenuItem->Enabled = true;
		SortToolStripMenuItem->Enabled = true;
		ChronPatientsToolStripMenuItem->Enabled = true;
		DiagnosisStatisticToolStripMenuItem->Enabled = true;
		DoctorPressureToolStripMenuItem->Enabled = true;
		toolStripButton1->Enabled = true;
		toolStripButton4->Enabled = true;
		toolStripButton5->Enabled = true;
		toolStripButton6->Enabled = true;
		toolStripButton7->Enabled = true;
		toolStripDropDownButton1->Enabled = true;
	}
}
private:
	String^ currentFileName;
private: System::Void SaveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ������ ��������� ���
	// ������� ���������� ���� ���������� �����
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = "Binary files (*.bin)|*.bin";
	saveFileDialog1->Title = "Save data to binary file";
	PatientInfo* info;
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		currentFileName = saveFileDialog1->FileName;
		FileStream^ fileStream = gcnew FileStream(currentFileName, FileMode::Create, FileAccess::Write);
		BinaryWriter^ binaryWriter = gcnew BinaryWriter(fileStream);
		for (int row = 0; row < dataGridView1->RowCount; row++)
		{
			PatientInfo patient;

			// ���������� ������ �� DataGridView � ���������� � ��������� PatientInfo
			String^ numberString = dataGridView1->Rows[row]->Cells[0]->Value->ToString();
			marshal_context^ context = gcnew marshal_context();
			const char* numberChars = context->marshal_as<const char*>(numberString);
			strcpy_s(patient.Number, numberChars);
			delete context;

			String^ nameString = dataGridView1->Rows[row]->Cells[1]->Value->ToString();
			context = gcnew marshal_context();
			const char* nameChars = context->marshal_as<const char*>(nameString);
			strcpy_s(patient.Name, nameChars);
			delete context;

			String^ dateOfBirthString = dataGridView1->Rows[row]->Cells[2]->Value->ToString();
			context = gcnew marshal_context();
			const char* dateOfBirthChars = context->marshal_as<const char*>(dateOfBirthString);
			strcpy_s(patient.DateOfBirth, dateOfBirthChars);
			delete context;

			String^ patientIDString = dataGridView1->Rows[row]->Cells[3]->Value->ToString();
			context = gcnew marshal_context();
			const char* patientIDChars = context->marshal_as<const char*>(patientIDString);
			strcpy_s(patient.PatientID, patientIDChars);
			delete context;

			String^ illnessString = dataGridView1->Rows[row]->Cells[4]->Value->ToString();
			context = gcnew marshal_context();
			const char* illnessChars = context->marshal_as<const char*>(illnessString);
			strcpy_s(patient.illness, illnessChars);
			delete context;

			String^ doctorString = dataGridView1->Rows[row]->Cells[5]->Value->ToString();
			context = gcnew marshal_context();
			const char* doctorChars = context->marshal_as<const char*>(doctorString);
			strcpy_s(patient.Doctor, doctorChars);
			delete context;

			String^ dateString = dataGridView1->Rows[row]->Cells[6]->Value->ToString();
			context = gcnew marshal_context();
			const char* dateChars = context->marshal_as<const char*>(dateString);
			strcpy_s(patient.DateOfVisit, dateChars);
			delete context;

			binaryWriter->Write(patient.Number);
			binaryWriter->Write(patient.Name);
			binaryWriter->Write(patient.DateOfBirth);
			binaryWriter->Write(patient.PatientID);
			binaryWriter->Write(patient.illness);
			binaryWriter->Write(patient.Doctor);
			binaryWriter->Write(patient.DateOfVisit);
		}
		binaryWriter->Close();
		fileStream->Close();
	}
};
private: System::Void SaveAsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ������ ���������
	if (isModified) {
		saveDataToFile(currentFileName);
	}
	else {
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "Binary files (*.bin)|*.bin";
			saveFileDialog->Title = "Save data to binary file";

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				// ������� ���������� ���� ���������� �����
				SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
				saveFileDialog1->Filter = "Binary files (*.bin)|*.bin";
				saveFileDialog1->Title = "Save data to binary file";
				if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					currentFileName = saveFileDialog1->FileName;
					if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
						currentFileName = saveFileDialog1->FileName;
						FileStream^ fileStream = gcnew FileStream(currentFileName, FileMode::Create, FileAccess::Write);
						BinaryWriter^ binaryWriter = gcnew BinaryWriter(fileStream);
						for (int row = 0; row < dataGridView1->RowCount; row++)
						{
							PatientInfo patient;

							// ���������� ������ �� DataGridView � ���������� � ��������� PatientInfo
							String^ numberString = dataGridView1->Rows[row]->Cells[0]->Value->ToString();
							marshal_context^ context = gcnew marshal_context();
							const char* numberChars = context->marshal_as<const char*>(numberString);
							strcpy_s(patient.Number, numberChars);
							delete context;

							String^ nameString = dataGridView1->Rows[row]->Cells[1]->Value->ToString();
							context = gcnew marshal_context();
							const char* nameChars = context->marshal_as<const char*>(nameString);
							strcpy_s(patient.Name, nameChars);
							delete context;

							String^ dateOfBirthString = dataGridView1->Rows[row]->Cells[2]->Value->ToString();
							context = gcnew marshal_context();
							const char* dateOfBirthChars = context->marshal_as<const char*>(dateOfBirthString);
							strcpy_s(patient.DateOfBirth, dateOfBirthChars);
							delete context;

							String^ patientIDString = dataGridView1->Rows[row]->Cells[3]->Value->ToString();
							context = gcnew marshal_context();
							const char* patientIDChars = context->marshal_as<const char*>(patientIDString);
							strcpy_s(patient.PatientID, patientIDChars);
							delete context;

							String^ illnessString = dataGridView1->Rows[row]->Cells[4]->Value->ToString();
							context = gcnew marshal_context();
							const char* illnessChars = context->marshal_as<const char*>(illnessString);
							strcpy_s(patient.illness, illnessChars);
							delete context;

							String^ doctorString = dataGridView1->Rows[row]->Cells[5]->Value->ToString();
							context = gcnew marshal_context();
							const char* doctorChars = context->marshal_as<const char*>(doctorString);
							strcpy_s(patient.Doctor, doctorChars);
							delete context;

							String^ dateString = dataGridView1->Rows[row]->Cells[6]->Value->ToString();
							context = gcnew marshal_context();
							const char* dateChars = context->marshal_as<const char*>(dateString);
							strcpy_s(patient.DateOfVisit, dateChars);
							delete context;

							binaryWriter->Write(patient.Number);
							binaryWriter->Write(patient.Name);
							binaryWriter->Write(patient.DateOfBirth);
							binaryWriter->Write(patient.PatientID);
							binaryWriter->Write(patient.illness);
							binaryWriter->Write(patient.Doctor);
							binaryWriter->Write(patient.DateOfVisit);
						}
						binaryWriter->Close();
						fileStream->Close();
					}
				}
			}
	}
}
void saveDataToFile(String^ fileName) {
	FileStream^ fs = gcnew FileStream(fileName, FileMode::Create);
	BinaryWriter^ bw = gcnew BinaryWriter(fs);
	for (int i = 0; i < dataGridView1->Rows->Count; i++) {
		for (int j = 0; j < dataGridView1->Columns->Count; j++) {
			if (dataGridView1->Rows[i]->Cells[j]->Value != nullptr) {
			String^ value = dataGridView1->Rows[i]->Cells[j]->Value->ToString();
			bw->Write(value);
			isDataSaved = true;
			}
		}
	}
}
private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) // ������� �������� ���������
{
	if (isModified && !isDataSaved) {
		if (MessageBox::Show("�� ������ ��������� ��������� ��������� ����� �������?", "�������� �����", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "Binary files (*.bin)|*.bin";
			saveFileDialog->Title = "Save data to binary file";

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				currentFileName = saveFileDialog->FileName;
				saveDataToFile(currentFileName);
				isDataSaved = true;
			}
		}
		else {
			e->Cancel = false;
			isModified = false;
			isDataSaved = false;
			this->Close();
		}
	}
}
private: System::Void DeletePatientToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedCells->Count > 0) { // ��������, ��� ���� ���������� ������
		int rowIndex = dataGridView1->SelectedCells[0]->RowIndex;
		if (MessageBox::Show("�� ������������� ������ ������� �������� " + dataGridView1->Rows[rowIndex]->Cells[1]->Value->ToString() + "?", "������������� ��������", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			int rowIndex = dataGridView1->SelectedCells[0]->RowIndex; // ��������� ������� ���������� ������
			dataGridView1->Rows->RemoveAt(rowIndex); // �������� ������ �� �������
		}
	}
}
private: System::Void SearchToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ������� ������ ��������
	bool isVisible = this->searchButton->Visible;
	this->searchButton->Visible = !isVisible;
	this->searchTextBox->Visible = !isVisible;
}
private: System::Void AboutProgrammToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ������ "� ���������"
	MessageBox::Show("������ ��������-1.3. ���� �������� �������������� �����������, ����� ���� �������� ����� ��� ����� \n"
		"���� �������� ��������� ���������-28.04.2023. \n"
		"@luvgreggs - ��������� ������ \n",
		"� ���������", MessageBoxButtons::OK);
}
private: System::Void FromFirstToLastToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ��� �� �����������
		dataGridView1->Sort(dataGridView1->Columns["Name"], ListSortDirection::Ascending);
}
private: System::Void FromLastToFirstToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ��� �� ��������
		dataGridView1->Sort(dataGridView1->Columns["Name"], ListSortDirection::Descending);
}
private: System::Void Accending�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ����� �� �����������
		dataGridView1->Sort(dataGridView1->Columns["Number"], ListSortDirection::Ascending);
}
private: System::Void DescendingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ����� �� ��������
	for (int i = 0; i < dataGridView1->Rows->Count; i++)
	{
		Object^ value = dataGridView1->Rows[i]->Cells["DateOfVisit"]->Value;
		if (value != nullptr)
		{
			DateTime dateOfBirth = Convert::ToDateTime(value);
			dataGridView1->Rows[i]->Cells["DateOfVisit"]->Value = dateOfBirth;
		}
	}
	dataGridView1->Columns["DateOfVisit"]->DefaultCellStyle->Format = "d";
	dataGridView1->Sort(dataGridView1->Columns["DateOfVisit"], ListSortDirection::Descending);
	for (int i = 0; i < dataGridView1->Rows->Count; i++) {
		Object^ value = dataGridView1->Rows[i]->Cells["DateOfVisit"]->Value;
		if (value != nullptr) {
			DateTime dateValue = safe_cast<DateTime>(value);
			String^ dateString = dateValue.ToString("d");
			dataGridView1->Rows[i]->Cells["DateOfVisit"]->Value = dateString;
		}
	}
}
private: System::Void RecentFirstToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ���� ��������� �� ������ ���������
	for (int i = 0; i < dataGridView1->Rows->Count; i++)
	{
		Object^ value = dataGridView1->Rows[i]->Cells["DateOfVisit"]->Value;
		if (value != nullptr)
		{
			DateTime dateOfBirth = Convert::ToDateTime(value);
			dataGridView1->Rows[i]->Cells["DateOfVisit"]->Value = dateOfBirth;
		}
	}
	dataGridView1->Columns["DateOfVisit"]->DefaultCellStyle->Format = "d";
	dataGridView1->Sort(dataGridView1->Columns["DateOfVisit"], ListSortDirection::Ascending);
	for (int i = 0; i < dataGridView1->Rows->Count; i++) {
		Object^ value = dataGridView1->Rows[i]->Cells["DateOfVisit"]->Value;
		if (value != nullptr) {
			DateTime dateValue = safe_cast<DateTime>(value);
			String^ dateString = dateValue.ToString("d");
			dataGridView1->Rows[i]->Cells["DateOfVisit"]->Value = dateString;
		}
	}
}
private: System::Void OldOnesFirstToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ���� ��������� �� ������ �������
		dataGridView1->Sort(dataGridView1->Columns["DateOfVisit"], ListSortDirection::Descending);
}
private: System::Void ChronPatientsButtonToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ������� ������������ ������ ��������� � ������������ �������������
		ChronicPatients^ chpatients = gcnew ChronicPatients();
		chpatients->Show();
		for (int i = 0; i < dataGridView1->Rows->Count; i++)
		{
			String^ value = dataGridView1->Rows[i]->Cells[4]->Value->ToString();
			int count = 0;
			bool alreadyAdded = false;
			for (int j = 0; j < dataGridView1->Rows->Count; j++)
			{
				if (dataGridView1->Rows[j]->Cells[4]->Value->ToString() == value)
				{
					count++;
					if (j < i)
						alreadyAdded = true;
				}
			}
			if (count >= 3 && !alreadyAdded)
			{
				array<Object^>^ values = gcnew array<Object^>(dataGridView1->Columns->Count);
				for (int j = 0; j < dataGridView1->Columns->Count; j++)
					values[j] = dataGridView1->Rows[i]->Cells[j]->Value;
				chpatients->AddRowToDataGridView(values);
			}
		}
}
private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) { // ������� ������ ������
	this->dataGridView1->ClearSelection();
	String^ searchText = this->searchTextBox->Text->ToLower();
	for each (DataGridViewRow ^ row in this->dataGridView1->Rows) {
		for each (DataGridViewCell ^ cell in row->Cells) {
			if (cell->Value != nullptr && cell->Value->ToString()->ToLower()->Contains(searchText)) {
				cell->Selected = true;
			}
		}
	}
}
private: System::Void dataGridView_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) { // �������������� ����������� �����
	for (int i = 0; i < e->RowCount; i++) {
		int rowIndex = e->RowIndex + i;
		this->dataGridView1->Rows[rowIndex]->Cells[0]->Value = (rowIndex + 1).ToString();
	}
}
private: System::Void GuideToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // �������� ����������� ������������
	System::Diagnostics::Process::Start("����������� ������������.docx");
}
private: System::Void CloseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ������ �������
	this->Close();
}
private: System::Void �������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	RedactForm^ redakt = gcnew RedactForm;
	redakt->Show();
	int rowind = dataGridView1->SelectedCells[0]->RowIndex;
	int colind = dataGridView1->SelectedCells[0]->ColumnIndex;

	int i = 0;
	for each (DataGridViewRow ^ row in dataGridView1->Rows)
	{
		if (i == rowind)
		{
			redakt->textBoxName->Text = row->Cells[1]->Value->ToString();
			redakt->dateTimePicker2->Text = row->Cells[2]->Value->ToString();
			redakt->textBoxillness->Text = row->Cells[4]->Value->ToString();
			redakt->textBoxPatientID->Text = row->Cells[3]->Value->ToString();
			redakt->textBoxDoctor->Text = row->Cells[5]->Value->ToString();
			redakt->dateTimePicker1->Text = row->Cells[6]->Value->ToString();
		}
		i++;
	}
	redakt->Visible = false;
	if (redakt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		dataGridView1->Rows[rowind]->Cells[1]->Value = redakt->textBoxName->Text;
		dataGridView1->Rows[rowind]->Cells[2]->Value = redakt->dateTimePicker2->Text;
		dataGridView1->Rows[rowind]->Cells[4]->Value = redakt->textBoxillness->Text;
		dataGridView1->Rows[rowind]->Cells[3]->Value = redakt->textBoxPatientID->Text;
		dataGridView1->Rows[rowind]->Cells[5]->Value = redakt->textBoxDoctor->Text;
		dataGridView1->Rows[rowind]->Cells[6]->Value = redakt->dateTimePicker1->Text;
	}
	changing = true;
}
private: System::Void contextMenuStrip1_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void contextMenuStrip1_Opening_1(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void Copy_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedCells->Count > 0) {
		Clipboard::SetText(dataGridView1->SelectedCells[0]->Value->ToString());
	}
}
private: System::Void Input_Click(System::Object^ sender, System::EventArgs^ e) {
	// ��������� �������� �� ������ ������
	String^ pasteText = Clipboard::GetText();

	// ��������, ��� ���� ���������� ������
	if (dataGridView1->SelectedCells->Count > 0)
	{
		// ��������� ������� ���������� ������
		int rowIndex = dataGridView1->SelectedCells[0]->RowIndex;
		int colIndex = dataGridView1->SelectedCells[0]->ColumnIndex;

		// ������� �������� � ������
		dataGridView1->Rows[rowIndex]->Cells[colIndex]->Value = pasteText;
	}
}
private: System::Void Cut_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedCells->Count > 0) {
		// �������� ��������� ����� �� ������� � ���������� �� � ������ ������
		Clipboard::SetDataObject(dataGridView1->GetClipboardContent());
		dataGridView1->ClearSelection();
	}
}
private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedCells->Count > 0) { // ��������, ��� ���� ���������� ������
		int rowIndex = dataGridView1->SelectedCells[0]->RowIndex;
		if (MessageBox::Show("�� ������������� ������ ������� �������� " + dataGridView1->Rows[rowIndex]->Cells[1]->Value->ToString() + "?", "������������� ��������", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			int rowIndex = dataGridView1->SelectedCells[0]->RowIndex; // ��������� ������� ���������� ������
			dataGridView1->Rows->RemoveAt(rowIndex); // �������� ������ �� �������
		}
	}
}
public:
	bool changing = false;
private: System::Void �������������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	RedactForm^ redakt = gcnew RedactForm;
	redakt->Show();
	int rowind = dataGridView1->SelectedCells[0]->RowIndex;
	int colind = dataGridView1->SelectedCells[0]->ColumnIndex;

	int i = 0;
	for each (DataGridViewRow ^ row in dataGridView1->Rows)
	{
		if (i == rowind)
		{
			redakt->textBoxName->Text = row->Cells[1]->Value->ToString();
			redakt->dateTimePicker2->Text = row->Cells[2]->Value->ToString();
			redakt->textBoxillness->Text = row->Cells[4]->Value->ToString();
			redakt->textBoxPatientID->Text = row->Cells[3]->Value->ToString();
			redakt->textBoxDoctor->Text = row->Cells[5]->Value->ToString();
			redakt->dateTimePicker1->Text = row->Cells[6]->Value->ToString();
		}
		i++;
	}
	redakt->Visible = false;
	if (redakt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		dataGridView1->Rows[rowind]->Cells[1]->Value = redakt->textBoxName->Text;
		dataGridView1->Rows[rowind]->Cells[2]->Value = redakt->dateTimePicker2->Text;
		dataGridView1->Rows[rowind]->Cells[4]->Value = redakt->textBoxillness->Text;
		dataGridView1->Rows[rowind]->Cells[3]->Value = redakt->textBoxPatientID->Text;
		dataGridView1->Rows[rowind]->Cells[5]->Value = redakt->textBoxDoctor->Text;
		dataGridView1->Rows[rowind]->Cells[6]->Value = redakt->dateTimePicker1->Text;
	}
	changing = true;
}
private: System::Void illnessAscendingToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Sort(dataGridView1->Columns["illness"], ListSortDirection::Ascending);
}
private: System::Void illnessDescendingToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Sort(dataGridView1->Columns["illness"], ListSortDirection::Descending);
}
private: System::Void DoctorAscendingToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Sort(dataGridView1->Columns["Doctor"], ListSortDirection::Ascending);
}
private: System::Void DoctorDescendingToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Sort(dataGridView1->Columns["Doctor"], ListSortDirection::Descending);
}
private: System::Void YoungGoFirstToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < dataGridView1->Rows->Count; i++)
	{
		Object^ value = dataGridView1->Rows[i]->Cells["DateOfBirth"]->Value;
		if (value != nullptr)
		{
			DateTime dateOfBirth = Convert::ToDateTime(value);
			dataGridView1->Rows[i]->Cells["DateOfBirth"]->Value = dateOfBirth;
		}
	}
	dataGridView1->Columns["DateOfBirth"]->DefaultCellStyle->Format = "d";
	dataGridView1->Sort(dataGridView1->Columns["DateOfBirth"], ListSortDirection::Descending);
	for (int i = 0; i < dataGridView1->Rows->Count; i++) {
		Object^ value = dataGridView1->Rows[i]->Cells["DateOfBirth"]->Value;
		if (value != nullptr) {
			DateTime dateValue = safe_cast<DateTime>(value);
			String^ dateString = dateValue.ToString("d");
			dataGridView1->Rows[i]->Cells["DateOfBirth"]->Value = dateString;
		}
	}
}
private: System::Void OldGoFirstToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < dataGridView1->Rows->Count; i++)
	{
		Object^ value = dataGridView1->Rows[i]->Cells["DateOfBirth"]->Value;
		if (value != nullptr)
		{
			DateTime dateOfBirth = Convert::ToDateTime(value);
			dataGridView1->Rows[i]->Cells["DateOfBirth"]->Value = dateOfBirth;
		}
	}
	dataGridView1->Columns["DateOfBirth"]->DefaultCellStyle->Format = "d";
	dataGridView1->Sort(dataGridView1->Columns["DateOfBirth"], ListSortDirection::Ascending);
	for (int i = 0; i < dataGridView1->Rows->Count; i++) {
		Object^ value = dataGridView1->Rows[i]->Cells["DateOfBirth"]->Value;
		if (value != nullptr) {
			DateTime dateValue = safe_cast<DateTime>(value);
			String^ dateString = dateValue.ToString("d");
			dataGridView1->Rows[i]->Cells["DateOfBirth"]->Value = dateString;
		}
	}
}
private: System::Void DiagnosisStatisticToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	label1->Visible = true;
	illnesschart->Visible = true;
	DoctorChart->Visible = false;
	label2->Visible = false;
	// ������� ������ � Chart
	this->illnesschart->Series["Series1"]->Points->Clear();
	// ������� ������� ��� �������� ���������� ������ �������
	Dictionary<String^, int>^ illnessCounts = gcnew Dictionary<String^, int>();

	// �������� ���������� ����� � DataGridView
	int rowCount = dataGridView1->RowCount;

	// ������������ ���������� ������ �������
	for (int i = 0; i < rowCount; i++) {
		String^ illness = dataGridView1->Rows[i]->Cells[4]->Value->ToString();
		if (illnessCounts->ContainsKey(illness)) {
			illnessCounts[illness]++;
		}
		else {
			illnessCounts[illness] = 1;
		}
	}
	// ��������� ������ � Chart
	for each (KeyValuePair<String^, int> ^ pair in illnessCounts) {
		this->illnesschart->Series["Series1"]->Points->AddXY(pair->Key, pair->Value);
	}
	// ������������� �������� ��� ��� Y ������ 1
	this->illnesschart->ChartAreas[0]->AxisY->Interval = 1;
}
private: System::Void DoctorPressureToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	label1->Visible = false;
	DoctorChart->Visible = true;
	illnesschart->Visible = false;
	label2->Visible = true;
	// ������� ������ � Chart
	this->DoctorChart->Series["Series1"]->Points->Clear();
	// ������� ������� ��� �������� ���������� ������ �������

	Dictionary<String^, int>^ doctorPressure = gcnew Dictionary<String^, int>();
	// �������� ���������� ����� � DataGridView
	int rowCount = dataGridView1->RowCount;

	// ������������ ���������� ������ �������
	for (int i = 0; i < rowCount; i++) {
		String^ doctor = dataGridView1->Rows[i]->Cells[5]->Value->ToString();
		if (doctorPressure->ContainsKey(doctor)) {
			doctorPressure[doctor]++;
		}
		else {
			doctorPressure[doctor] = 1;
		}
	}
	// ��������� ������ � Chart
	for each (KeyValuePair<String^, int> ^ pair in doctorPressure) {
		this->DoctorChart->Series["Series1"]->Points->AddXY(pair->Key, pair->Value);
	}
	// ������������� �������� ��� ��� Y ������ 1
	this->DoctorChart->ChartAreas[0]->AxisY->Interval = 1;
}
private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) { // ��������� ���
	// ������� ���������� ���� ���������� �����
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = "Binary files (*.bin)|*.bin";
	saveFileDialog1->Title = "Save data to binary file";
	PatientInfo* info;
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		currentFileName = saveFileDialog1->FileName;
		FileStream^ fileStream = gcnew FileStream(currentFileName, FileMode::Create, FileAccess::Write);
		BinaryWriter^ binaryWriter = gcnew BinaryWriter(fileStream);
		for (int row = 0; row < dataGridView1->RowCount; row++)
		{
			PatientInfo patient;

			// ���������� ������ �� DataGridView � ���������� � ��������� PatientInfo
			String^ numberString = dataGridView1->Rows[row]->Cells[0]->Value->ToString();
			marshal_context^ context = gcnew marshal_context();
			const char* numberChars = context->marshal_as<const char*>(numberString);
			strcpy_s(patient.Number, numberChars);
			delete context;

			String^ nameString = dataGridView1->Rows[row]->Cells[1]->Value->ToString();
			context = gcnew marshal_context();
			const char* nameChars = context->marshal_as<const char*>(nameString);
			strcpy_s(patient.Name, nameChars);
			delete context;

			String^ dateOfBirthString = dataGridView1->Rows[row]->Cells[2]->Value->ToString();
			context = gcnew marshal_context();
			const char* dateOfBirthChars = context->marshal_as<const char*>(dateOfBirthString);
			strcpy_s(patient.DateOfBirth, dateOfBirthChars);
			delete context;

			String^ patientIDString = dataGridView1->Rows[row]->Cells[3]->Value->ToString();
			context = gcnew marshal_context();
			const char* patientIDChars = context->marshal_as<const char*>(patientIDString);
			strcpy_s(patient.PatientID, patientIDChars);
			delete context;

			String^ illnessString = dataGridView1->Rows[row]->Cells[4]->Value->ToString();
			context = gcnew marshal_context();
			const char* illnessChars = context->marshal_as<const char*>(illnessString);
			strcpy_s(patient.illness, illnessChars);
			delete context;

			String^ doctorString = dataGridView1->Rows[row]->Cells[5]->Value->ToString();
			context = gcnew marshal_context();
			const char* doctorChars = context->marshal_as<const char*>(doctorString);
			strcpy_s(patient.Doctor, doctorChars);
			delete context;

			String^ dateString = dataGridView1->Rows[row]->Cells[6]->Value->ToString();
			context = gcnew marshal_context();
			const char* dateChars = context->marshal_as<const char*>(dateString);
			strcpy_s(patient.DateOfVisit, dateChars);
			delete context;

			binaryWriter->Write(patient.Number);
			binaryWriter->Write(patient.Name);
			binaryWriter->Write(patient.DateOfBirth);
			binaryWriter->Write(patient.PatientID);
			binaryWriter->Write(patient.illness);
			binaryWriter->Write(patient.Doctor);
			binaryWriter->Write(patient.DateOfVisit);
		}
		binaryWriter->Close();
		fileStream->Close();
	}
}
private: System::Void toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) { // ���������
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Title = "Open binary file";
	openFileDialog->Filter = "Binary files (*.bin)|*.bin";
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ fileName = openFileDialog->FileName;
		currentFileName = fileName;
		FileStream^ fs = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
		BinaryReader^ br = gcnew BinaryReader(fs);

		// �������� ������ �� ��������� ����� � DataGridView
		int i = 0;
		dataGridView1->Rows->Clear();
		while (br->PeekChar() != -1)
		{
			PatientInfo patient;

			// ������ ������ ��������� PatientInfo �� ��������� �����
			array<Byte>^ numberBytes = br->ReadBytes(sizeof(patient.Number));
			pin_ptr<unsigned char> numberPinPtr = &numberBytes[0];
			memcpy_s(patient.Number, sizeof(patient.Number), numberPinPtr, sizeof(patient.Number));

			array<Byte>^ nameBytes = br->ReadBytes(sizeof(patient.Name));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> namePinPtr = &nameBytes[0];
				memcpy_s(patient.Name, sizeof(patient.Name), namePinPtr, sizeof(patient.Name));
			}

			array<Byte>^ DateOfBirthBytes = br->ReadBytes(sizeof(patient.DateOfBirth));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> DateOfBirthPinPtr = &DateOfBirthBytes[0];
				memcpy_s(patient.DateOfBirth, sizeof(patient.DateOfBirth), DateOfBirthPinPtr, sizeof(patient.DateOfBirth));
			}

			array<Byte>^ PatientIDBytes = br->ReadBytes(sizeof(patient.PatientID));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> PatientIDPinPtr = &PatientIDBytes[0];
				memcpy_s(patient.PatientID, sizeof(patient.PatientID), PatientIDPinPtr, sizeof(patient.PatientID));
			}

			array<Byte>^ illnessBytes = br->ReadBytes(sizeof(patient.illness));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> illnessPinPtr = &illnessBytes[0];
				memcpy_s(patient.illness, sizeof(patient.illness), illnessPinPtr, sizeof(patient.illness));
			}
			array<Byte>^ DoctorBytes = br->ReadBytes(sizeof(patient.Doctor));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> DoctorPinPtr = &DoctorBytes[0];
				memcpy_s(patient.Doctor, sizeof(patient.Doctor), DoctorPinPtr, sizeof(patient.Doctor));
			}

			array<Byte>^ DateOfVisitBytes = br->ReadBytes(sizeof(patient.DateOfVisit));
			if (nameBytes->Length > 0)
			{
				pin_ptr<unsigned char> DateOfVisitPinPtr = &DateOfVisitBytes[0];
				memcpy_s(patient.DateOfVisit, sizeof(patient.DateOfVisit), DateOfVisitPinPtr, sizeof(patient.DateOfVisit));
			}
			// ���������� ������ � DataGridView
			array<String^>^ row = gcnew array<String^>{
				gcnew String(patient.Number),
					gcnew String(patient.Name),
					gcnew String(patient.DateOfBirth),
					gcnew String(patient.PatientID),
					gcnew String(patient.illness),
					gcnew String(patient.Doctor),
					gcnew String(patient.DateOfVisit)
					// ����������� ��� ��������� ����� ��������� PatientInfo
			};

			dataGridView1->Rows->Add(row);
		}
		br->Close();
		fs->Close();
	}
}
private: System::Void toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) { // ��������
	AddPatientForm^ addPatient = gcnew AddPatientForm;
	addPatient->Show();
	addPatient->Visible = false;
	if (addPatient->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		dataGridView1->Rows->Add(addPatient->InputValues);
	}
	else {
		MessageBox::Show("������� �� ��� ��������", "���������� ��������", MessageBoxButtons::OK);
	}
}
private: System::Void toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) { // �������������
	RedactForm^ redakt = gcnew RedactForm;
	redakt->Show();
	int rowind = dataGridView1->SelectedCells[0]->RowIndex;
	int colind = dataGridView1->SelectedCells[0]->ColumnIndex;

	int i = 0;
	for each (DataGridViewRow ^ row in dataGridView1->Rows)
	{
		if (i == rowind)
		{
			redakt->textBoxName->Text = row->Cells[1]->Value->ToString();
			redakt->dateTimePicker2->Text = row->Cells[2]->Value->ToString();
			redakt->textBoxillness->Text = row->Cells[4]->Value->ToString();
			redakt->textBoxPatientID->Text = row->Cells[3]->Value->ToString();
			redakt->textBoxDoctor->Text = row->Cells[5]->Value->ToString();
			redakt->dateTimePicker1->Text = row->Cells[6]->Value->ToString();
		}
		i++;
	}
	redakt->Visible = false;
	if (redakt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		dataGridView1->Rows[rowind]->Cells[1]->Value = redakt->textBoxName->Text;
		dataGridView1->Rows[rowind]->Cells[2]->Value = redakt->dateTimePicker2->Text;
		dataGridView1->Rows[rowind]->Cells[4]->Value = redakt->textBoxillness->Text;
		dataGridView1->Rows[rowind]->Cells[3]->Value = redakt->textBoxPatientID->Text;
		dataGridView1->Rows[rowind]->Cells[5]->Value = redakt->textBoxDoctor->Text;
		dataGridView1->Rows[rowind]->Cells[6]->Value = redakt->dateTimePicker1->Text;
	}
	changing = true;
}
private: System::Void toolStripButton5_Click(System::Object^ sender, System::EventArgs^ e) { // �������
	if (dataGridView1->SelectedCells->Count > 0) { // ��������, ��� ���� ���������� ������
		int rowIndex = dataGridView1->SelectedCells[0]->RowIndex;
		if (MessageBox::Show("�� ������������� ������ ������� �������� " + dataGridView1->Rows[rowIndex]->Cells[1]->Value->ToString() + "?", "������������� ��������", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			int rowIndex = dataGridView1->SelectedCells[0]->RowIndex; // ��������� ������� ���������� ������
			dataGridView1->Rows->RemoveAt(rowIndex); // �������� ������ �� �������
		}
	}
}
private: System::Void toolStripButton6_Click(System::Object^ sender, System::EventArgs^ e) { // �����
	bool isVisible = this->searchButton->Visible;
	this->searchButton->Visible = !isVisible;
	this->searchTextBox->Visible = !isVisible;
}
private: System::Void toolStripButton7_Click(System::Object^ sender, System::EventArgs^ e) { // ����������� ��������
	ChronicPatients^ chpatients = gcnew ChronicPatients();
	chpatients->Show();
	for (int i = 0; i < dataGridView1->Rows->Count; i++)
	{
		String^ value = dataGridView1->Rows[i]->Cells[4]->Value->ToString();
		int count = 0;
		bool alreadyAdded = false;
		for (int j = 0; j < dataGridView1->Rows->Count; j++)
		{
			if (dataGridView1->Rows[j]->Cells[4]->Value->ToString() == value)
			{
				count++;
				if (j < i)
					alreadyAdded = true;
			}
		}
		if (count >= 3 && !alreadyAdded)
		{
			array<Object^>^ values = gcnew array<Object^>(dataGridView1->Columns->Count);
			for (int j = 0; j < dataGridView1->Columns->Count; j++)
				values[j] = dataGridView1->Rows[i]->Cells[j]->Value;
			chpatients->AddRowToDataGridView(values);
		}
	}
}
private: System::Void ������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	label1->Visible = true;
	illnesschart->Visible = true;
	DoctorChart->Visible = false;
	label2->Visible = false;
	// ������� ������ � Chart
	this->illnesschart->Series["Series1"]->Points->Clear();
	// ������� ������� ��� �������� ���������� ������ �������
	Dictionary<String^, int>^ illnessCounts = gcnew Dictionary<String^, int>();

	// �������� ���������� ����� � DataGridView
	int rowCount = dataGridView1->RowCount;

	// ������������ ���������� ������ �������
	for (int i = 0; i < rowCount; i++) {
		String^ illness = dataGridView1->Rows[i]->Cells[4]->Value->ToString();
		if (illnessCounts->ContainsKey(illness)) {
			illnessCounts[illness]++;
		}
		else {
			illnessCounts[illness] = 1;
		}
	}
	// ��������� ������ � Chart
	for each (KeyValuePair<String^, int> ^ pair in illnessCounts) {
		this->illnesschart->Series["Series1"]->Points->AddXY(pair->Key, pair->Value);
	}
	// ������������� �������� ��� ��� Y ������ 1
	this->illnesschart->ChartAreas[0]->AxisY->Interval = 1;
}
private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	label1->Visible = false;
	DoctorChart->Visible = true;
	illnesschart->Visible = false;
	label2->Visible = true;
	// ������� ������ � Chart
	this->DoctorChart->Series["Series1"]->Points->Clear();
	// ������� ������� ��� �������� ���������� ������ �������

	Dictionary<String^, int>^ doctorPressure = gcnew Dictionary<String^, int>();
	// �������� ���������� ����� � DataGridView
	int rowCount = dataGridView1->RowCount;

	// ������������ ���������� ������ �������
	for (int i = 0; i < rowCount; i++) {
		String^ doctor = dataGridView1->Rows[i]->Cells[5]->Value->ToString();
		if (doctorPressure->ContainsKey(doctor)) {
			doctorPressure[doctor]++;
		}
		else {
			doctorPressure[doctor] = 1;
		}
	}
	// ��������� ������ � Chart
	for each (KeyValuePair<String^, int> ^ pair in doctorPressure) {
		this->DoctorChart->Series["Series1"]->Points->AddXY(pair->Key, pair->Value);
	}
	// ������������� �������� ��� ��� Y ������ 1
	this->DoctorChart->ChartAreas[0]->AxisY->Interval = 1;
}
private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("������ ��������-1.3. ���� �������� �������������� �����������, ����� ���� �������� ����� ��� ����� \n"
		"���� �������� ��������� ���������-28.04.2023. \n"
		"@luvgreggs - ��������� ������ \n",
		"� ���������", MessageBoxButtons::OK);
}
private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Diagnostics::Process::Start("����������� ������������.docx");
}
private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("�������� ���������, �������������� ��������� �������� � ����������� ����������� : �.�.�., ���� ��������, ����� ������, �������, �.�.�.�������� �����, ���� ���������. "
		"���������� �������� ������� �����, ������ ���������� �� ������������(� ���� ���������), ������������ ������ ���������, ���������� ������������ �������������(�.�.������������ � ����� ����� 3 ��� � ������� ���� � ����� � ��� �� ���������)",
		"� ������� ", MessageBoxButtons::OK);
}
private: System::Void toolStripButton1_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton2_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton3_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton4_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton5_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton6_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton7_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripDropDownButton1_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripDropDownButton2_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
};
}
