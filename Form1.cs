namespace WinFormsApp1
{
    public partial class Form1 : Form

    {

        List<BankAccount> bankAccounts = new List<BankAccount>();
        public Form1()
        {
            InitializeComponent();

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(ControlOwnertxt.Text))
            {
                return;
            }

            BankAccount bankAccount = new BankAccount(ControlOwnertxt.Text);
            bankAccounts.Add(bankAccount);

            RefreshGrid();

            ControlOwnertxt.Text = null;


        }

        private void RefreshGrid()
        {
            BankAccountGrid.DataSource = null;
            BankAccountGrid.DataSource = bankAccounts;
        }

        private void DepositBtn_Click(object sender, EventArgs e)
        {
            if (BankAccountGrid.SelectedRows.Count == 1)
            {
                BankAccount SelectedBankAccount = BankAccountGrid.SelectedRows[0].DataBoundItem as BankAccount;

                string message = SelectedBankAccount.Deposite(AmountNum.Value);

                RefreshGrid();
                AmountNum.Value = 0;
                MessageBox.Show(message);
            }
        }

        private void WithdrawBtn_Click(object sender, EventArgs e)
        {
            if (BankAccountGrid.SelectedRows.Count == 1)
            {
                BankAccount SelectedBankAccount = BankAccountGrid.SelectedRows[0].DataBoundItem as BankAccount;


                string message = SelectedBankAccount.Withdraw(AmountNum.Value);

                RefreshGrid();

                AmountNum.Value = 0;
                MessageBox.Show(message);
            }

        }
    }
}
