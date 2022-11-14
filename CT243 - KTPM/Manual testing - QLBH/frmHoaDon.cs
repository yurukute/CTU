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
    public partial class frmHoaDon : Form
    {
        //Khai báo biến kiểm tra việc Thêm hay Sửa dữ liệu
        bool Them;
        //Chuỗi kết nối
        //string strConnectionString = @"Server=.\SQLEXPRESS;Database=QuanLyBanHang;Integrated Security=True";
        //or
        string strConnectionString=@"Data Source=.\SQLEXPRESS;Initial Catalog=QuanLyBanHang;Integrated Security=SSPI";

        //Đối tượng kết nối
        SqlConnection conn = null;
        //Đối tượng đưa dữ liệu vào DataTable dtHoaDon = null;
        SqlDataAdapter daHoaDon = null;
        //Đối tượng hiển thị dữ liệu lên Form
        DataTable dtHoaDon = null;

        //Thêm cho ví dụ 10.5
        //Đối tượng đưa dữ liệu vào DataTable dtKhachHang = null;
        SqlDataAdapter daKhachHang = null;
        //Đối tượng hiển thị dữ liệu lên Form
        DataTable dtKhachHang = null;

        SqlDataAdapter daNhanVien = null;
        //Đối tượng hiển thị dữ liệu lên Form
        DataTable dtNhanVien = null;

        public frmHoaDon()
        {
            InitializeComponent();
        }

        void LoadData()
        {
            try
            {
                //Khởi động kết nối
                conn = new SqlConnection(strConnectionString);

                //Vận chuyển dữ liệu lên DataTable dtHoaDon
                daHoaDon = new SqlDataAdapter("SELECT * FROM HoaDon", conn);
                dtHoaDon = new DataTable();
                dtHoaDon.Clear();
                daHoaDon.Fill(dtHoaDon);
                //Đưa dữ liệu lên DataGridView
                this.dgvHoaDon.DataSource = dtHoaDon;

                //Bổ sung thêm cho ví dụ 10.5
                //Vận chuyển dữ liệu lên DataTable dtKhachHang dùng cho combobox
                daKhachHang = new SqlDataAdapter("SELECT * FROM KhachHang", conn);
                dtKhachHang = new DataTable();
                dtKhachHang.Clear();
                daKhachHang.Fill(dtKhachHang);

                //Vận chuyển dữ liệu lên DataTable dtHoaDon
                daNhanVien = new SqlDataAdapter("SELECT MaNV, (Ho + ' ' + Ten) AS HoTen FROM NhanVien", conn);
                dtNhanVien = new DataTable();
                dtNhanVien.Clear();
                daNhanVien.Fill(dtNhanVien);

                //  Đưa dữ liệu lên ComboBox trong DataGridView   
                (dgvHoaDon.Columns["MaKH"] as DataGridViewComboBoxColumn).DataSource = dtKhachHang;
                (dgvHoaDon.Columns["MaKH"] as DataGridViewComboBoxColumn).DisplayMember = "TenCty";
                (dgvHoaDon.Columns["MaKH"] as DataGridViewComboBoxColumn).ValueMember = "MaKH";

                //  Đưa dữ liệu lên ComboBox trong DataGridView   
                (dgvHoaDon.Columns["MaNV"] as DataGridViewComboBoxColumn).DataSource = dtNhanVien;
                (dgvHoaDon.Columns["MaNV"] as DataGridViewComboBoxColumn).DisplayMember = "HoTen";
                (dgvHoaDon.Columns["MaNV"] as DataGridViewComboBoxColumn).ValueMember = "MaNV";

                //Xóa các đối tượng trong Panel
                this.txtMaHD.ResetText();
                this.txtNgayLapHD.ResetText();
                this.txtNgayNhanHang.ResetText();
                //Không cho thao tác trên các nút Lưu / Hủy
                this.btnLuu.Enabled = false;
                this.btnHuy.Enabled = false;
                this.pnlThongTinHD.Enabled = false;
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
        private void frmHoaDon_Load(object sender, EventArgs e)
        {
            LoadData();
        }

        private void frmHoaDon_FormClosing(object sender, FormClosingEventArgs e)
        {
            //Giải phóng tài nguyên
            dtHoaDon.Dispose();
            dtHoaDon = null;
            //hủy kết nối
            conn = null;
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
                int r = dgvHoaDon.CurrentCell.RowIndex;
                //Lấy MaKH của record hiện hành
                string strMAHD = dgvHoaDon.Rows[r].Cells[0].Value.ToString();
                //Viết câu lệnh SQL
                cmd.CommandText = System.String.Concat("Delete from HoaDon where MaHD='" + strMAHD + "'");
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
            this.txtMaHD.ResetText();
            this.txtNgayLapHD.ResetText();
            this.txtNgayNhanHang.ResetText();
 
            //Cho thao tác trên các nút Thêm / Sửa / Xóa / Thoát
            this.btnThem.Enabled = true;
            this.btnSua.Enabled = true;
            this.btnXoa.Enabled = true;
            this.btnThoat.Enabled = true;
            //Không cho thao tác trên các nút Lưu / Hủy / Panel
            this.btnLuu.Enabled = false;
            this.btnHuy.Enabled = false;
            this.pnlThongTinHD.Enabled = false;
        }

        private void btnThem_Click(object sender, EventArgs e)
        {
            //Kích hoạt biến Them
            Them = true;
            //Xóa trống các đối tượng trong Panel
            this.txtMaHD.ResetText();
            this.txtNgayLapHD.ResetText();
            this.txtNgayNhanHang.ResetText();

            //Cho thao tác trên các nút Lưu / Hủy / Panel
            this.btnLuu.Enabled = true;
            this.btnHuy.Enabled = true;
            this.pnlThongTinHD.Enabled = true;
            //Không cho thao tác trên các nút Thêm / Xóa / Thoát
            this.btnThem.Enabled = false;
            this.btnSua.Enabled = false;
            this.btnXoa.Enabled = false;
            this.btnThoat.Enabled = false;
            //Đưa dữ liệu lên ComboBox
            this.cbMaKH.DataSource = dtKhachHang;
            this.cbMaKH.DisplayMember = "TenCty";
            this.cbMaKH.ValueMember = "MaKH";

            this.cbMaNV.DataSource = dtNhanVien;
            this.cbMaNV.DisplayMember = "Ten";
            this.cbMaNV.ValueMember = "MaNV";

            //Đưa con trỏ đến TextField txtMaHD
            this.txtMaHD.Focus();
        }

        private void btnSua_Click(object sender, EventArgs e)
        {
            //Kích hoạt biến Sửa
            Them = false;
            //Đưa dữ liệu lên 2 ComboBox
            this.cbMaKH.DataSource = dtKhachHang;
            this.cbMaKH.DisplayMember = "TenCty";
            this.cbMaKH.ValueMember = "MaKH";

            this.cbMaNV.DataSource = dtNhanVien;
            this.cbMaNV.DisplayMember = "Ten";
            this.cbMaNV.ValueMember = "MaNV";

            //Cho phép thao tác trên Panel
            this.pnlThongTinHD.Enabled = true;
            //Thứ tự dòng hiện hành
            int r = dgvHoaDon.CurrentCell.RowIndex;
            //Chuyển thông tin lên panel
            this.txtMaHD.Text = dgvHoaDon.Rows[r].Cells[0].Value.ToString();
            this.cbMaKH.SelectedValue = dgvHoaDon.Rows[r].Cells[1].Value.ToString();
            this.cbMaNV.SelectedValue = dgvHoaDon.Rows[r].Cells[2].Value.ToString();
            this.txtNgayLapHD.Text = dgvHoaDon.Rows[r].Cells[3].Value.ToString();
            this.txtNgayNhanHang.Text = dgvHoaDon.Rows[r].Cells[4].Value.ToString();

            //Cho thao tác trên các nút Lưu / Hủy / Panel
            this.btnLuu.Enabled = true;
            this.btnHuy.Enabled = true;
            this.pnlThongTinHD.Enabled = true;
            //Không cho thao tác trên các nút thêm / Sửa / Xóa / Thoát
            this.btnThem.Enabled = false;
            this.btnSua.Enabled = false;
            this.btnXoa.Enabled = false;
            this.btnXoa.Enabled = false;
            this.btnThoat.Enabled = false;
            //Đưa con trỏ đến TextField txtMaKH
            this.txtMaHD.Focus();

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
                    cmd.CommandText = System.String.Concat("Insert into HoaDon values(" + "'" +
                        this.txtMaHD.Text.ToString() + "','" + this.cbMaKH.SelectedValue.ToString() + "','" +
                        this.cbMaNV.SelectedValue.ToString() + "','" + this.txtNgayLapHD.Text.ToString() + "','" +
                        this.txtNgayNhanHang.Text.ToString()+"')");
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
                    int r = dgvHoaDon.CurrentCell.RowIndex;
                    //MaKH hiện hành
                    string strMAHD = dgvHoaDon.Rows[r].Cells[0].Value.ToString();
                    //Câu lệnh SQL
                    cmd.CommandText = System.String.Concat("Update HoaDon Set MaHD='"+
                        this.txtMaHD.Text.ToString() + "', MaKH ='" + 
                        this.cbMaKH.SelectedValue.ToString() + "', MaNV ='" + this.cbMaNV.SelectedValue.ToString() 
                        + "', NgayLapHD ='" + this.txtNgayLapHD.Text.ToString() + "', MaKH ='" + this.txtNgayNhanHang.Text.ToString() + 
                        "' where MaHD ='" + strMAHD + "'");
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

        private void btnThoat_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnReLoad_Click(object sender, EventArgs e)
        {
            LoadData();
        }

   }
}
