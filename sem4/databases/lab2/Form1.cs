using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace HomeWork1
{
    public partial class Form1 : Form
    {

        SqlConnection conn;
        SqlDataAdapter datableParent;
        SqlDataAdapter datableChild;
        DataSet ds;
        BindingSource bsParent;
        BindingSource bsChild;
        SqlCommandBuilder cmdBuilder;
        string queryParent;
        string queryChild;


        public Form1()
        {
            InitializeComponent();
            FillData();
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        void FillData()
        {
            conn = new SqlConnection(getConnectionString());

            queryParent = "SELECT * from "+ ConfigurationManager.AppSettings["ParentTableName"];
            queryChild = "SELECT * from " + ConfigurationManager.AppSettings["ChildTableName"];
            datableParent = new SqlDataAdapter(queryParent, conn);
            datableChild = new SqlDataAdapter(queryChild, conn);
            ds = new DataSet();
            datableParent.Fill(ds, ConfigurationManager.AppSettings["ParentTableName"]);
            datableChild.Fill(ds, ConfigurationManager.AppSettings["ChildTableName"]);

            cmdBuilder = new SqlCommandBuilder(datableChild);

            ds.Relations.Add(ConfigurationManager.AppSettings["RelationName"], ds.Tables[ConfigurationManager.AppSettings["ParentTableName"]].Columns[ConfigurationManager.AppSettings["RelationColumnFK"]],
                ds.Tables[ConfigurationManager.AppSettings["ChildTableName"]].Columns[ConfigurationManager.AppSettings["RelationColumnFK"]]);

            bsParent = new BindingSource();
            bsParent.DataSource = ds.Tables[ConfigurationManager.AppSettings["ParentTableName"]];

            bsChild = new BindingSource();
            bsChild.DataSource = bsParent;
            bsChild.DataMember = ConfigurationManager.AppSettings["RelationName"];

            this.dataGridView1.DataSource = bsParent;
            this.dataGridView2.DataSource = bsChild;
            this.label1.Text = ConfigurationManager.AppSettings["ParentTableName"];
            this.label2.Text = ConfigurationManager.AppSettings["ChildTableName"];
        }

        string getConnectionString()
        {

            string conString = "Data Source=" + ConfigurationManager.AppSettings["Data Source"] + ";" + "Initial Catalog=" + ConfigurationManager.AppSettings["Initial Catalog"] + ";Integrated Security=True";
            return conString;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {

                datableChild.Update(ds, ConfigurationManager.AppSettings["ChildTableName"]);
                MessageBox.Show("updated successfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error updating data: " + ex.Message);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {

                datableChild.Update(ds, ConfigurationManager.AppSettings["ChildTableName"]);
                MessageBox.Show("added successfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error Inserting data: " + ex.Message);
            }
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (dataGridView2.SelectedRows.Count > 0)
            {
                int rowIndex = dataGridView2.SelectedRows[0].Index;

                DataGridViewRow selectedRow = dataGridView2.SelectedRows[0];

                DataRowView selectedDataRowView = (DataRowView)selectedRow.DataBoundItem;
                DataRow selectedDataRow = selectedDataRowView.Row;


                try
                {
                    selectedDataRow.Delete();
                    datableChild.Update(ds, ConfigurationManager.AppSettings["ChildTableName"]);
                    MessageBox.Show("deleted successfully");
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error deleting row: " + ex.Message);
                }
            }
            else
            {
                MessageBox.Show("Please select a row to delete");
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {
            
        }
    }
}