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

namespace QuanLyBanHang
{
    public partial class frmKhachHang : Form
    {
        //Khai báo biến kiểm tra việc Thêm hay Sửa dữ liệu
        bool Them;
        //Chuỗi kết nối
        //string strConnectionString = @"Server=.\SQLEXPRESS;Database=QuanLyBanHang;Integrated Security=True";
        //or
        string strConnectionString=@"Data Source=.\SQLEXPRESS;Initial Catalog=QuanLyBanHang;Integrated Security=SSPI";

        //Đối tượng kết nối
        SqlConnection conn = null;
        //Đối tượng đưa dữ liệu vào DataTable dtKhachHang = null;
        SqlDataAdapter daKhachHang = null;
        //Đối tượng hiển thị dữ liệu lên Form
        DataTable dtKhachHang = null;

        //Thêm cho ví dụ 10.5
        //Đối tượng đưa dữ liệu vào DataTable dtThanhPho = null;
        SqlDataAdapter daThanhPho = null;
        //Đối tượng hiển thị dữ liệu lên Form
        DataTable dtThanhPho = null;

        public frmKhachHang()
        {
            InitializeComponent();
        }

        private void btnThoat_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        void LoadData()
        {
            try
            {
                //Khởi động kết nối
                conn = new SqlConnection(strConnectionString);

                //Vận chuyển dữ liệu lên DataTable dtThanhPho
                daThanhPho = new SqlDataAdapter("SELECT * FROM ThanhPho", conn);
                dtThanhPho = new DataTable();
                dtThanhPho.Clear();
                daThanhPho.Fill(dtThanhPho);

                //  Đưa dữ liệu lên ComboBox trong DataGridView   
                (dgvKhachHang.Columns["ThanhPho"] as DataGridViewComboBoxColumn).DataSource = dtThanhPho;
                (dgvKhachHang.Columns["ThanhPho"] as DataGridViewComboBoxColumn).DisplayMember = "TenThanhPho";
                (dgvKhachHang.Columns["ThanhPho"] as DataGridViewComboBoxColumn).ValueMember = "ThanhPho"; 

                //Vận chuyển dữ liệu lên DataTable dtKhachHang
                daKhachHang = new SqlDataAdapter("SELECT * FROM Khachhang", conn);
                dtKhachHang = new DataTable();
                dtKhachHang.Clear();
                daKhachHang.Fill(dtKhachHang);
                //Đưa dữ liệu lên DataGridView
                this.dgvKhachHang.DataSource = dtKhachHang;
                //Thay đổi độ rộng cột
                dgvKhachHang.AutoResizeColumns();

                //Bổ sung thêm cho ví dụ 10.5

                
               //Xóa các đối tượng trong Panel
                this.txtMaKH.ResetText();
                this.txtTenCty.ResetText();
                this.txtDienthoai.ResetText();
                //Không cho thao tác trên các nút Lưu / Hủy
                this.btnLuu.Enabled = false;
                this.btnHuy.Enabled = false;
                this.pnlThongTinKH.Enabled = false;
                //Cho thao tác trên các nút Thêm / Sửa / Xóa / Thoát
                this.btnThem.Enabled = true;
                this.btnSua.Enabled = true;
                this.btnXoa.Enabled = true;
                this.btnThoat.Enabled = true;
            }
            catch (SqlException)
            {
                MessageBox.Show("Không lấy được nội dung trong table Khachhang. Lỗi rồi!!!");
            }
        }
        private void frmKhachHang_Load(object sender, EventArgs e)
        {
            LoadData();
        }

        private void frmKhachHang_FormClosing(object sender, FormClosingEventArgs e)
        {
            //Giải phóng tài nguyên
            dtKhachHang.Dispose();
            dtKhachHang = null;
            //hủy kết nối
            conn = null;
        }

        private void btnReLoad_Click(object sender, EventArgs e)
        {
            LoadData();
        }

        private void btnXoa_Click(object sender, EventArgs e)
        {
            //Mở kết nối
            conn.Open();
            try
            {
                //Thực hiện lệnh
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandType = CommandType.Text;
                //Lấy thứ tự record hiện hành
                int r = dgvKhachHang.CurrentCell.RowIndex;
                //Lấy MaKH của record hiện hành
                string strMAKH = dgvKhachHang.Rows[r].Cells[0].Value.ToString();
                //Viết câu lệnh SQL
                cmd.CommandText = System.String.Concat("Delete from KhachHang where MaKH='" + strMAKH + "'");
                //cmd.CommandType = CommandType.Text;
                //Thực hiện câu lệnh SQL
                cmd.ExecuteNonQuery();
                //Cập nhật lại DataGridView
                LoadData();
                //Thông báo
                MessageBox.Show("Đã xóa xong!");

            }
            catch(SqlException){
                MessageBox.Show("Không xóa được. Lỗi rồi!!!");
            }
            //Đóng kết nối
            conn.Close();
        }

        private void btnHuy_Click(object sender, EventArgs e)
        {
            //Xóa trống các đối tượng trong panel
            this.txtMaKH.ResetText();
            this.txtTenCty.ResetText();
            this.txtDiachi.ResetText();
            this.txtDienthoai.ResetText();
            //Cho thao tác trên các nút Thêm / Sửa / Xóa / Thoát
            this.btnThem.Enabled = true;
            this.btnSua.Enabled = true;
            this.btnXoa.Enabled = true;
            this.btnThoat.Enabled = true;
            //Không cho thao tác trên các nút Lưu / Hủy / Panel
            this.btnLuu.Enabled = false;
            this.btnHuy.Enabled = false;
            this.pnlThongTinKH.Enabled = false;
        }

        private void btnThem_Click(object sender, EventArgs e)
        {
            //Kích hoạt biến Them
            Them = true;
            //Xóa trống các đối tượng trong Panel
            this.txtMaKH.ResetText();
            this.txtTenCty.ResetText();
            this.txtDiachi.ResetText();
            this.txtDienthoai.ResetText();
            //Cho thao tác trên các nút Lưu / Hủy / Panel
            this.btnLuu.Enabled = true;
            this.btnHuy.Enabled = true;
            this.pnlThongTinKH.Enabled = true;
            //Không cho thao tác trên các nút Thêm / Xóa / Thoát
            this.btnThem.Enabled = false;
            this.btnSua.Enabled = false;
            this.btnXoa.Enabled = false;
            this.btnThoat.Enabled = false;
            //Đưa dữ liệu lên ComboBox
            this.cbThanhPho.DataSource = dtThanhPho;
            this.cbThanhPho.DisplayMember = "TenThanhPho";
            this.cbThanhPho.ValueMember = "ThanhPho";
            //Đưa con trỏ đến TextField txtMaKH
            this.txtMaKH.Focus();
        }

        private void btnSua_Click(object sender, EventArgs e)
        {
            //Kích hoạt biến Sửa
            Them = false;
            //Đưa dữ liệu lên ComboBox
            this.cbThanhPho.DataSource = dtThanhPho;
            this.cbThanhPho.DisplayMember = "TenThanhPho";
            this.cbThanhPho.ValueMember = "ThanhPho";
            //Cho phép thao tác trên Panel
            this.pnlThongTinKH.Enabled = true;
            //Thứ tự dòng hiện hành
            int r = dgvKhachHang.CurrentCell.RowIndex;
            //Chuyển thông tin lên panel
            this.txtMaKH.Text = dgvKhachHang.Rows[r].Cells[0].Value.ToString();
            this.txtTenCty.Text = dgvKhachHang.Rows[r].Cells[1].Value.ToString();
            this.txtDiachi.Text = dgvKhachHang.Rows[r].Cells[2].Value.ToString();
            this.cbThanhPho.SelectedValue = dgvKhachHang.Rows[r].Cells[3].Value.ToString();
            this.txtDienthoai.Text = dgvKhachHang.Rows[r].Cells[4].Value.ToString();
            //Cho thao tác trên các nút Lưu / Hủy / Panel
            this.btnLuu.Enabled = true;
            this.btnHuy.Enabled = true;
            this.pnlThongTinKH.Enabled = true;
            //Không cho thao tác trên các nút thêm / Sửa / Xóa / Thoát
            this.btnThem.Enabled = false;
            this.btnSua.Enabled = false;
            this.btnXoa.Enabled = false;
            this.btnXoa.Enabled = false;
            this.btnThoat.Enabled = false;
            //Đưa con trỏ đến TextField txtMaKH
            this.txtMaKH.Focus();

        }

        private void btnLuu_Click(object sender, EventArgs e)
        {
            //Mở kết nối
            conn.Open();
            if(Them)
            {
                try
                {
                    //Thực hiện lệnh
                    SqlCommand cmd = new SqlCommand();
                    cmd.Connection = conn;
                    cmd.CommandType = CommandType.Text;
                    //Lệnh Insert InTo
                    cmd.CommandText = System.String.Concat("Insert into KhachHang values(" + "'" + 
                        this.txtMaKH.Text.ToString() + "',N'" + this.txtTenCty.Text.ToString() + "',N'" +
                        this.txtDiachi.Text.ToString() + "','" + this.cbThanhPho.SelectedValue.ToString() + "','" +
                        this.txtDienthoai.Text.ToString() + "')");
                    cmd.CommandType = CommandType.Text;
                    cmd.ExecuteNonQuery();
                    //Load lại dữ liệu trên DataGridView
                    LoadData();
                    //Thông báo
                    MessageBox.Show("Đã thêm xong!");
                }
                catch (SqlException)
                {
                    MessageBox.Show("Không thêm được. Lỗi rồi!");
                }
            }//if

            //for updating data
            if(!Them)
            {
                try
                {
                    //Thực hiện lệnh
                    SqlCommand cmd = new SqlCommand();
                    cmd.Connection = conn;
                    cmd.CommandType = CommandType.Text;
                    //Thứ tự dòng hiện hành
                    int r = dgvKhachHang.CurrentCell.RowIndex;
                    //MaKH hiện hành
                    string strMAKH = dgvKhachHang.Rows[r].Cells[0].Value.ToString();
                    //Câu lệnh SQL
                    cmd.CommandText = System.String.Concat("Update KhachHang Set TenCty=N'"+
                        this.txtTenCty.Text.ToString() + "', Diachi ='N" + 
                        this.txtDiachi.Text.ToString() + "', ThanhPho ='" + this.cbThanhPho.SelectedValue.ToString()
                        + "', DienThoai ='" + this.txtDienthoai.Text.ToString() + "', MaKH ='" + this.txtMaKH.Text.ToString() + 
                        "' where MaKH ='" + strMAKH + "'");
                    //Cập nhật
                    cmd.CommandType = CommandType.Text;
                    cmd.ExecuteNonQuery();
                    //Load lại dữ liệu lên trên DataGridView
                    LoadData();
                    //Thông báo
                    MessageBox.Show("Đã sửa xong!");
                }
                catch(SqlException)
                {
                    MessageBox.Show("Không sửa được. Lỗi rồi!");
                }
            }
            //Đóng kết nối
            conn.Close();
        }
    }
}
