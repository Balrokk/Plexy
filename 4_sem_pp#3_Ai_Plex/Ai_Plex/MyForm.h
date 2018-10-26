#pragma once

#include <string>
#include <msclr/marshal_cppstd.h>

#include "TPlex.h"

namespace Ai_Plex {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button8;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(12, 124);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(544, 188);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->SizeChanged += gcnew System::EventHandler(this, &MyForm::pictureBox1_SizeChanged);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(421, 78);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(54, 8);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Открыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(94, 39);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(116, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Нарисовать линию";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Файл:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Действия:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(94, 78);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(116, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Передвинуть точку";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(240, 39);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(118, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Передвинуть плекс";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(240, 78);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(118, 23);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Закрасить точку";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(384, 39);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(112, 23);
			this->button7->TabIndex = 9;
			this->button7->Text = L"Закрасить линию";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"plex";
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Plex files|*.plex";
			this->openFileDialog1->Title = L"Открыть плекс";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"plex";
			this->saveFileDialog1->FileName = L"Plex1";
			this->saveFileDialog1->Filter = L"Plex files|*.plex";
			this->saveFileDialog1->Title = L"Сохранить плекс";
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::saveFileDialog1_FileOk);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(381, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Цвет:";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(151, 8);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 11;
			this->button8->Text = L"Сохранить";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(680, 324);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		int flag;
		TPlex *plex;
		PointName *pointname;
		Graphics^ g;
		TPoint* Left;
		TPoint* Right;

	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		flag = 2;
	}
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Left = nullptr;
	Right = nullptr;

	int x = e->X;
	int y = e->Y;

	if (flag == 0) {
		if (plex->isNotEmpty())
			Left = plex->CheckPoint(x, y);
		if (Left == nullptr)
			Left = new TPoint(pointname->Get(), x, y);
	}
	if (flag == 1) {
		if (plex->isNotEmpty())
			Left = plex->CheckPoint(x, y);
	}
	if (flag == 2) {
		Left = new TPoint("temp", x, y);
	}
	if (flag == 3) {
		if (plex->isNotEmpty())
			Left = plex->CheckPoint(x, y);
	}
}
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	int x = e->X;
	int y = e->Y;

	TLine *line;

	if (flag == 0) {
		if (plex->isNotEmpty())
			Right = plex->CheckPoint(x, y);
		if (Left != nullptr)
			if (Left->isInArea(x, y))
				Right = Left;
		if (Left != Right)
		{
			if (Right == nullptr)
				Right = new TPoint(pointname->Get(), x, y);
			line = new TLine(Left, Right);
			if (!plex->AddLine(line))
			{
				MessageBox::Show("Невозможно нарисовать линию");
				delete line;
			}
		}
	}
	if (flag == 1) {
		if (Left != nullptr)
			if (!Left->isInArea(x, y))
				Left->Move(x - Left->getX(), y - Left->getY());
	}
	if (flag == 2) {
		if (plex->isNotEmpty())
			plex->Move(x - Left->getX(), y - Left->getY());
		delete Left;
	}
	if (flag == 3) {
		if (Left != nullptr)
			if (Left->isInArea(x, y))
				Left->setColor(button1->BackColor);
	}
	if (flag == 4) {
		TLine *line = nullptr;
		if (plex->isNotEmpty())
			line = plex->CheckLine(x, y);
		if (line != nullptr)
			line->setColor(button1->BackColor);
	}


	g->Clear(Color::White);
	if (plex->isNotEmpty())
		plex->Draw(g);
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	flag = 0;
}
private: System::Void pictureBox1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
	g = pictureBox1->CreateGraphics();
	g->Clear(Color::White);
	if (plex->isNotEmpty())
		plex->Draw(g);
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	flag = 1;
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	plex = new TPlex();

	flag = 0;
	button1->BackColor = colorDialog1->Color;

	pointname = new PointName();
	g = pictureBox1->CreateGraphics();
}
private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	delete plex;
}
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	flag = 3;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		button1->BackColor = colorDialog1->Color;
	}
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	flag = 4;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ filename = openFileDialog1->FileName;
		plex->Load(msclr::interop::marshal_as<std::string>(filename));
		g->Clear(Color::White);
		plex->Draw(g);

		pointname->SetLastName(plex->getLastPoint());
		pointname->Get();
	}
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ filename = saveFileDialog1->FileName;
		plex->Save(msclr::interop::marshal_as<std::string>(filename));
	}
}
};
}
