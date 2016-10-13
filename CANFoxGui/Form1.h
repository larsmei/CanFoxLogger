#pragma once
#include "CANLIB.h"


namespace CANFoxGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Zusammenfassung für Form1
	///
	/// Warnung: Wenn Sie den Namen dieser Klasse ändern, müssen Sie auch
	///          die Ressourcendateiname-Eigenschaft für das Tool zur Kompilierung verwalteter Ressourcen ändern,
	///          das allen RESX-Dateien zugewiesen ist, von denen diese Klasse abhängt.
	///          Anderenfalls können die Designer nicht korrekt mit den lokalisierten Ressourcen
	///          arbeiten, die diesem Formular zugewiesen sind.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		CANBus* cFox;
		CANBus* cFSend;
		unsigned char* sendData8;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  tb_D8;
	private: System::Windows::Forms::TextBox^  tb_D7;
	private: System::Windows::Forms::TextBox^  tb_D6;
	private: System::Windows::Forms::TextBox^  tb_D5;
	private: System::Windows::Forms::TextBox^  tb_D4;
	private: System::Windows::Forms::TextBox^  tb_D3;
	private: System::Windows::Forms::TextBox^  tb_D2;
	private: System::Windows::Forms::TextBox^  tb_D1;
	private: System::Windows::Forms::TextBox^  tb_ID;
	private: System::Windows::Forms::Button^  b_SendSingle;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  description;
	private: System::Windows::Forms::ColumnHeader^  telegram;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;




	public: 
		CANBus::BAUDRATES baudrate;
		Form1(void)
		{


			
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
			loggingActive = false;
			button1->Text=sStartLog;
				
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::ComboBox^  comboBox1;


	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		bool loggingActive;
		static String^ sStartLog="Start Logging";
		static String^ sStopLog="Stop Logging";
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->b_SendSingle = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_D8 = (gcnew System::Windows::Forms::TextBox());
			this->tb_D7 = (gcnew System::Windows::Forms::TextBox());
			this->tb_D6 = (gcnew System::Windows::Forms::TextBox());
			this->tb_D5 = (gcnew System::Windows::Forms::TextBox());
			this->tb_D4 = (gcnew System::Windows::Forms::TextBox());
			this->tb_D3 = (gcnew System::Windows::Forms::TextBox());
			this->tb_D2 = (gcnew System::Windows::Forms::TextBox());
			this->tb_D1 = (gcnew System::Windows::Forms::TextBox());
			this->tb_ID = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->description = (gcnew System::Windows::Forms::ColumnHeader());
			this->telegram = (gcnew System::Windows::Forms::ColumnHeader());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 18;
			this->listBox1->Location = System::Drawing::Point(13, 18);
			this->listBox1->Name = L"listBox1";
			this->listBox1->ScrollAlwaysVisible = true;
			this->listBox1->Size = System::Drawing::Size(475, 580);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Form1::backgroundWorker1_ProgressChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->Location = System::Drawing::Point(13, 604);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 36);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start Logging";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"1000 kBit/s", L"800 kBit/s", L"500 kBit/s", L"250 kBit/s", 
				L"125 kBit/s", L"100 kBit/s", L"50 kBit/s", L"20 kBit/s"});
			this->comboBox1->Location = System::Drawing::Point(268, 19);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(186, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(179, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Select Baudrate";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(494, 18);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(460, 107);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"HW-Settings";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->b_SendSingle);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->tb_D8);
			this->groupBox2->Controls->Add(this->tb_D7);
			this->groupBox2->Controls->Add(this->tb_D6);
			this->groupBox2->Controls->Add(this->tb_D5);
			this->groupBox2->Controls->Add(this->tb_D4);
			this->groupBox2->Controls->Add(this->tb_D3);
			this->groupBox2->Controls->Add(this->tb_D2);
			this->groupBox2->Controls->Add(this->tb_D1);
			this->groupBox2->Controls->Add(this->tb_ID);
			this->groupBox2->Location = System::Drawing::Point(494, 131);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(460, 84);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"send single message";
			// 
			// b_SendSingle
			// 
			this->b_SendSingle->Location = System::Drawing::Point(325, 39);
			this->b_SendSingle->Name = L"b_SendSingle";
			this->b_SendSingle->Size = System::Drawing::Size(75, 23);
			this->b_SendSingle->TabIndex = 9;
			this->b_SendSingle->Text = L"send";
			this->b_SendSingle->UseVisualStyleBackColor = true;
			this->b_SendSingle->Click += gcnew System::EventHandler(this, &Form1::b_SendSingle_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(271, 25);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(21, 13);
			this->label10->TabIndex = 1;
			this->label10->Text = L"D8";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(244, 25);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(21, 13);
			this->label9->TabIndex = 1;
			this->label9->Text = L"D7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(217, 25);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(21, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"D6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(190, 25);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"D5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(163, 25);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"D4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(136, 25);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"D3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(109, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(21, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"D2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(82, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"D1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ID";
			// 
			// tb_D8
			// 
			this->tb_D8->Location = System::Drawing::Point(274, 41);
			this->tb_D8->MaxLength = 2;
			this->tb_D8->Name = L"tb_D8";
			this->tb_D8->Size = System::Drawing::Size(21, 20);
			this->tb_D8->TabIndex = 8;
			// 
			// tb_D7
			// 
			this->tb_D7->Location = System::Drawing::Point(247, 41);
			this->tb_D7->MaxLength = 2;
			this->tb_D7->Name = L"tb_D7";
			this->tb_D7->Size = System::Drawing::Size(21, 20);
			this->tb_D7->TabIndex = 7;
			// 
			// tb_D6
			// 
			this->tb_D6->Location = System::Drawing::Point(220, 41);
			this->tb_D6->MaxLength = 2;
			this->tb_D6->Name = L"tb_D6";
			this->tb_D6->Size = System::Drawing::Size(21, 20);
			this->tb_D6->TabIndex = 6;
			// 
			// tb_D5
			// 
			this->tb_D5->Location = System::Drawing::Point(193, 41);
			this->tb_D5->MaxLength = 2;
			this->tb_D5->Name = L"tb_D5";
			this->tb_D5->Size = System::Drawing::Size(21, 20);
			this->tb_D5->TabIndex = 5;
			// 
			// tb_D4
			// 
			this->tb_D4->Location = System::Drawing::Point(166, 41);
			this->tb_D4->MaxLength = 2;
			this->tb_D4->Name = L"tb_D4";
			this->tb_D4->Size = System::Drawing::Size(21, 20);
			this->tb_D4->TabIndex = 4;
			// 
			// tb_D3
			// 
			this->tb_D3->Location = System::Drawing::Point(139, 41);
			this->tb_D3->MaxLength = 2;
			this->tb_D3->Name = L"tb_D3";
			this->tb_D3->Size = System::Drawing::Size(21, 20);
			this->tb_D3->TabIndex = 3;
			// 
			// tb_D2
			// 
			this->tb_D2->Location = System::Drawing::Point(112, 41);
			this->tb_D2->MaxLength = 2;
			this->tb_D2->Name = L"tb_D2";
			this->tb_D2->Size = System::Drawing::Size(21, 20);
			this->tb_D2->TabIndex = 2;
			// 
			// tb_D1
			// 
			this->tb_D1->Location = System::Drawing::Point(85, 41);
			this->tb_D1->MaxLength = 2;
			this->tb_D1->Name = L"tb_D1";
			this->tb_D1->Size = System::Drawing::Size(21, 20);
			this->tb_D1->TabIndex = 1;
			// 
			// tb_ID
			// 
			this->tb_ID->Location = System::Drawing::Point(31, 41);
			this->tb_ID->MaxLength = 3;
			this->tb_ID->Name = L"tb_ID";
			this->tb_ID->Size = System::Drawing::Size(48, 20);
			this->tb_ID->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->Controls->Add(this->listView1);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(494, 221);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(459, 416);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"predefined messages";
			// 
			// listView1
			// 
			this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->description, this->telegram});
			this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(6, 27);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(447, 332);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView1_SelectedIndexChanged);
			// 
			// description
			// 
			this->description->Text = L"Description";
			this->description->Width = 206;
			// 
			// telegram
			// 
			this->telegram->Text = L"Telegram";
			this->telegram->Width = 225;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button3->Location = System::Drawing::Point(6, 368);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(147, 36);
			this->button3->TabIndex = 0;
			this->button3->Text = L"load message file";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(966, 649);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"Form1";
			this->Text = L"CANFoxGui V0.3 - Lars Meindl";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				 comboBox1->SelectedIndex=4;
				 baudrate = CANBus::B125k;

				 
			 }

	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }


	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				while (true)
				{
					if (cFox == NULL)
					{
						break;
					}

			 		cFox->readMsg();
				 	for ( int i = 0; i < cFox->msgCount; i++ )
					{
						// Dies muss doch ein fehler gewesen sein oder?
						// ich muss das mit Hardware prüfen
						//for (int k = 0; k < cFox->msgCount; k++ )
						//{
							backgroundWorker1->ReportProgress(1,gcnew System::String(cFox->getMsg()));
						//}
					}
				}
			 }
			 
	private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {

				 listBox1->Items->Add(e->UserState);
				 listBox1->SelectedIndex = listBox1->Items->Count-1;
				
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (!loggingActive)
			 {
				try 
				{
					cFox = new CANBus(105L,1L,1L,-1L,1000L,baudrate);
					cFox->filterOff();
					backgroundWorker1->RunWorkerAsync();
				}
				catch ( long e )
				{
					MessageBox::Show("Hardware not found!");
					return;
				}
				loggingActive=true;
				button1->Text=sStopLog;
			 }else
			 {
				 delete(cFox);
				 cFox = NULL;
				 backgroundWorker1->CancelAsync();
				 button1->Text=sStartLog;
			 }

		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 delete(cFox);
			 cFox = NULL;
			 backgroundWorker1->CancelAsync();
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 switch ( comboBox1->SelectedIndex )
			 {
				 case 0:
					   baudrate = CANBus::B1000k;
					   break;
				 case 1:
					 baudrate = CANBus::B800k;
					   break;
				 case 2:
					 baudrate = CANBus::B500k;
					   break;
				 case 3:
					 baudrate = CANBus::B250k;
					   break;
				 case 4:
					 baudrate = CANBus::B125k;
					   break;
				 default:
					 baudrate = CANBus::B125k;
			 }

		 }

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void b_SendSingle_Click(System::Object^  sender, System::EventArgs^  e) {

			try 
			{
				cFSend = new CANBus(105L,1L,1L,-1L,1000L,baudrate);
			}
			catch ( long e )
			{
				MessageBox::Show("Hardware not found!");
				return;
			}

			sendData8 = new unsigned char[8];

			sendData8[0] = Convert::ToInt16(tb_D1->Text,16);
			sendData8[1] = Convert::ToInt16(tb_D2->Text,16);
			sendData8[2] = Convert::ToInt16(tb_D3->Text,16);
			sendData8[3] = Convert::ToInt16(tb_D4->Text,16);
			sendData8[4] = Convert::ToInt16(tb_D5->Text,16);
			sendData8[5] = Convert::ToInt16(tb_D6->Text,16);
			sendData8[6] = Convert::ToInt16(tb_D7->Text,16);
			sendData8[7] = Convert::ToInt16(tb_D8->Text,16);

			cFSend->sendMsg8(Convert::ToInt16(tb_ID->Text,16),sendData8);

			delete[](sendData8);
			delete(cFSend);
			cFSend = NULL;

		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

			 if ( openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK )
			 {
				 IO::StreamReader^ file = gcnew IO::StreamReader(openFileDialog1->OpenFile());
				 
				 listView1->Items->Clear();

				 String^ line;
				 Windows::Forms::ListViewItem^ item;
				 array<String^>^ token;
				 array<Char>^ chars={'-'};
				 
				 line = file->ReadLine();
				 while ( line != nullptr )
				 {
					 token = line->Split(chars);
					 item = listView1->Items->Add(token[0]);
					 item->SubItems->Add(token[1]);

					 line = file->ReadLine();
				 }
			 }

		 }
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 array<String^>^ token;
			 array<Char>^ chars={' '};

			 IEnumerator^ tmp = listView1->SelectedItems->GetEnumerator();
			 if (tmp->MoveNext())
			 {
				 ListViewItem^ tmp2 = safe_cast<ListViewItem^>(tmp->Current);

				 token = tmp2->SubItems[1]->Text->Split(chars);
				 tb_ID->Text = token[1];
				 tb_D1->Text = token[2];
				 tb_D2->Text = token[3];
				 tb_D3->Text = token[4];
				 tb_D4->Text = token[5];
				 tb_D5->Text = token[6];
				 tb_D6->Text = token[7];
				 tb_D7->Text = token[8];
				 tb_D8->Text = token[9];
			 }

			 

		 }
};
}

