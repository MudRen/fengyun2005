// Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "流沙");
	set("long", @LONG
你已经陷入流沙之中，四周没有一点着力的地方。你一点点地向下落去。除非
有人拉(pull)你一把，想活着离开这里恐怕比登天还难。你似乎已经看到黑白无常
在向你招手。
LONG
	);

        set("NONPC",1);
	set("coor/x",-1070);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}

void init()
{	object ob;
	if( interactive( ob = this_player()))
	{
	remove_call_out("sinking");
	call_out("sinking", 1, ob);
	}
}

int sinking(object ob)

{
	int i;
	int damage;
        if( ob && environment(ob) == this_object())
	{
	message_vision(HIW"$N又在流沙中陷深了一些！！", ob);
	message_vision("$N几乎在绝望中哭了出来！！\n"NOR, ob);
	damage = random(5)+1;
	i =  (int)ob->query("kee");
	ob->set("kee",(int) i - damage);
	if( environment(ob) == this_object())
	call_out("sinking",random(5)+5, ob);	
	}
	else

	return 1;
}

void reset(){
	object *inv;
	int num,i;	
	::reset();
	inv = all_inventory();
	for (i=0;i<sizeof(inv);i++){
		if (userp(inv[i])) {
			message_vision(HIW"李寻欢用尽全身力量，将$N从流沙中救了出来。\n"NOR, inv[i]);
			sscanf(file_name(this_object()),__DIR__"quiclsamd%d",num);
        	inv[i]->move(__DIR__"desert"+num);
        	tell_object(inv[i],CYN"\n李寻欢拍拍你的脑袋，以后小心啦，说罢便消失了！\n\n"NOR);
		}
	}
}	