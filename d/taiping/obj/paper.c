
inherit ITEM;

void create()
{
        set_name("短信", ({"paper", "letter"}) );
		set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("no_split",1);
                set("long", "小纸片上只有寥寥两行：

你到这里来才半天，已有多少人要杀你？你要不要人帮你？
                
            三爷
\n");
                set("value", 1);
        }
}

