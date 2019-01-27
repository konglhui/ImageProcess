using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImageView
{
    class ParamData
    {
        public static Dictionary<string, double> paramData = new Dictionary<string, double>();
    }

    /// <summary>
    /// 图像节点
    /// </summary>
    class Node
    {
        private Bitmap image;
        private Node next;

        public Node()
        {
            image = default(Bitmap);
            next = null;
        }
        public Node(Bitmap image)
        {
            this.image = image;
            this.next = null;
        }

        public Bitmap Image
        {
            get{ return image; }
            set{ image = value; }
        }

        public Node Next
        {
            get { return next; }
            set { next = value; }
        }
    }



    /// <summary>
    /// Bitmap链表
    /// </summary>
    class MyLinkedList
    {
        Node node;

        public MyLinkedList()
        {
            node = new Node();
        }

        public MyLinkedList(Bitmap image)
        {
            node = new Node(image);
        }

        public void Add(Bitmap image)
        {
            Node temp = new Node(image);
            if (node.Image == default(Bitmap))
            {
                node = temp;
            }
            else
            {
                Node n = node;
                while (n.Next != null)
                {
                    n = n.Next;
                }
                n.Next = temp;
            }
        }

        public void ClearImage()
        {
            node = new Node();
        }

        public Bitmap getItem(int i)
        {

            if (i == 0)
                return node.Image;
            Node temp = node;
            int j = 0;

            while(temp.Next != null &&j<i)
            {
                j++;
                temp = temp.Next;
            }

            if(j == i)
            {
                return temp.Image;
            }
            else
            {
                return default(Bitmap);
            }
        }
    }
}
