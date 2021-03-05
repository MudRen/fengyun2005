#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("如意燧链", ({ "keychain" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long","
这是一根细细小小的链子，乍看上去没有什么稀奇的地方，
但据说上面可以系住许多东西备用。不过，在使用之前先
需要激活。
");
                set("value", 300000);
				set("destination","none");
				set("material", "steel");
				set("desc_ext","激活（activate）");
        }
        ::init_item();
}


void init()
{
   	add_action("do_activate","activate");
}
    
    
int do_activate(string arg)
{
    	object me = this_player();

		if (!arg || arg!="keychain")	{
			tell_object(me,"格式：activate keychain\n");
			return 1;
		}
		
		if (REWARD_D->check_m_success(me,"如意燧链")) {
			tell_object(me,"你已经拥有如意息链了！\n");
			return 1;
		}
					
		tell_object(me, "
你激活了如意燧链的功能，具体的使用方法，请参考ｈｅｌｐ　ｋｅｙｃｈａｉｎ\n")	;	
		
        REWARD_D->riddle_done(me,"如意燧链",10,1);
        destruct(this_object());
    	return 1;
}

