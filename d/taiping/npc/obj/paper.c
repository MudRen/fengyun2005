
inherit ITEM;

void create()
{
        set_name("地图", ({"paper", "map",  "纸"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "那是一张地图，简简单单画着一个庄院。墨画的地图，上面却有两个大红色交叉，
一个在转墙旁边，一个却是在一座小楼之上，旁边还有两个字——血奴。
地图下角写着：左三右五左七，可开后墙铁门。
\n");
                set("value", 1);
        }
}

