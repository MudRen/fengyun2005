
inherit ITEM;

void create()
{
        set_name("发黄的纸", ({"paper", "bao map",  "纸"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张已经发黄了的纸，上面的字迹残缺不全，你隐约可辨四个字。
	神水                   
                       定力
\n");
                set("value", 1);
        }
}

