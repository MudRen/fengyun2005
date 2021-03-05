
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("公文", ({"gongwen"}) );
	set_weight(5);
	set("long", "这是张缉拿犯人的公文纸，抬头空着还未填写。（print）\n");
	set("unit", "张");
        set("value", 10000);
        set("official_seal",1);
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
		
	if (query("printed"))
		message_vision("$N掏出块橡皮把公文纸的抬头擦了擦。\n", this_player());
		
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
	else tarobj = find_living(target);	
	
	if( !tarobj || (tarobj && tarobj->query("wiz_invis"))) {
		message_vision("$N把" + target + "填在$n犯人姓名一栏上。\n", this_player(), this_object());
		this_object()->set("long",
			"这是一张公文纸，上面缉拿歹人一栏里写着『" + target + "』。\n");
        }
        else {
	   	message_vision("$N把" + tarobj->name() + "填在$n犯人姓名一栏上。\n", this_player(), this_object());
	   	this_object()->set("hunted_name",tarobj->query("id"));
	   	this_object()->set("long",
				"这是一张公文纸，上面缉拿歹人一栏里写着『" + tarobj->name() + "』。\n");
           	if (userp(tarobj)) this_object()->set("players",1);
        }
        this_object()->set("targetid", target);
        this_object()->set("printed",1);
        return 1;
}


