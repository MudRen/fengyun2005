
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("油油的纸", ({"youzhi"}) );
	set_weight(5);
	set("long","这是张油斑点点的破纸片儿，左下角草草地画了一个骷髅头，
中间留着很大一块空白，可以写字（print）\n");
	set("unit", "张");
    set("value", 1);
	::init_item();
}


void init()
{
  if(this_player()==environment())
  	add_action("do_print","print");

}

int do_print(string arg)
{
        object obj, tarobj, tempobj;
        string sheet, target;

		if( !arg || sscanf(arg, "%s", target)!=1 )
			return notify_fail("指令格式：print <姓名> \n");
	
		tempobj = present(target, environment(this_player()));
		if (tempobj)
		{
			if (!living(tempobj))
			{
				tarobj = find_living(target);
			}
			else
				tarobj = tempobj;
		}
		else 
			tarobj = find_living(target);	
	
		if( !tarobj || (objectp(tarobj) && tarobj->query("wiz_invis"))) {
			message_vision("$N把" + target + "写在$n上。\n", this_player(), this_object());
				this_object()->set("long",
				"这是一张" + this_object()->name() + "，上面写着＂" + target + "＂几个小字．\n");
        }
        else {
	   		message_vision("$N把" + tarobj->name() + "写在$n上。\n", this_player(), this_object());
	   		set("targetname",tarobj->name());
	   		set("targetgender",tarobj->query("gender"));
	   		set("long",
			"这是一张油油的纸，上面写着＂" + tarobj->name() + "＂几个小字．\n");
           	if (userp(tarobj)) 
           		set("players",1);
        }
        set("targetid", target);
        return 1;
}


