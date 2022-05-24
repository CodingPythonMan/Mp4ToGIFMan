using System;
using System.Collections.Generic;
using System.Windows.Forms;
using SharpAvi;

namespace Jeff
{
    public partial class Form1 : Form
    {
        Recorder record;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FourCC selectedCodec = KnownFourCCs.Codecs.MotionJpeg;

            RecorderParams recparams = new RecorderParams("D:\\recordvideo.mp4", 49, selectedCodec, 100);

            record = new Recorder(recparams);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            record.Dispose();
        }
    }
}
