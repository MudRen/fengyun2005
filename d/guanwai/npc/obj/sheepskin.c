inherit ITEM;

void create()
{
        set_name("羊皮诗卷", ({"sheep skin", "sheepskin",  "skin"}) );
	set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "张");
                set("long", "一张十分破旧的羊皮诗卷，字迹模糊不过依稀可以辨认：
     　　见 醉 酒 儿
     　　心 后 须 须
     　　言 畅 醉 成
     　　   谈    名
\n");
                set("value", 0);
        }
	::init_item();
}
