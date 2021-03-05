inherit ROOM;
#include <ansi.h>
int blinding(object me);
int bbqthem(object me, object obj);

void create()
{
        set("short", "小巷尽头");
        set("long", @LONG
小巷没多远就到了尽头，一盏灰暗的马灯挂在墙上，风吹过咣咣地响，似乎时
刻都会熄灭。两侧仍然是暗褐色的高墙，仍然没有窗子，也没有人声。地上有一滩
污水，上面胡乱堆着许多麻袋，旁边还有一辆平板车。
LONG
        );
        set("exits", ([ 
		"southwest": __DIR__"droad3",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
 
	]));
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",0);
	set("map","taiping");
	setup();

}

void init()
{
        add_action("do_look","look");

}

int do_look(string arg)
{
        object oldworm;
    	oldworm=present("oldworm",this_object());
    	
    	if (arg == "麻袋" || arg=="平板车" || arg =="cart" || arg=="bag"){
  		if (oldworm && !userp(oldworm)) {
  			tell_object(this_player(),"鼓鼓囊囊的湿麻袋里装满了发霉的麦子，旁边停着辆歪歪扭扭的平板车。\n");
  			tell_object(this_player(),HIR"你仔细一看，平板车上竟然有两具尸体！穿黑衣的尸体！\n"NOR);
  			message_vision(CYN"\n\n$N狞笑一声：“天堂有路你不走，地狱无门你偏要闯。你也躺下吧。”\n\n"NOR,oldworm);
  			oldworm->kill_ob(this_player());
  			this_player()->kill_ob(oldworm);
  		} else 
  			tell_object(this_player(),"鼓鼓囊囊的湿麻袋里装满了发霉的麦子，旁边停着辆歪歪扭扭的平板车。\n");  	
		return 1;
	}
    	return 0;
}


	
int blinding(object ob) {
	object *enemy;
	enemy=ob->query_enemy();
	if (!enemy || sizeof(enemy)<1)	return 1;
	message_vision(HIW"\n$N忽然一挥手抖出一包石灰，白粉飞散，附近一带立时就像是陷入漫天迷雾之中。\n"NOR,ob);
	foreach (object x in enemy) {
		if (x->query_temp("block_msg/all")) continue;
		bbqthem(ob,x);
	}
	return 1;
}

int bbqthem(object me, object enemy) 
{
	if(enemy->query("combat_exp")>random(me->query("combat_exp")*5))
        {
        	message_vision(HIB"$N连忙转过头去，避开白粉。\n"NOR,enemy);
        	return 1;
        }
	tell_object(enemy,HIW"你只觉得眼前白茫茫的一片，什么都看不到了。。。\n"NOR);
	enemy->add_temp("block_msg/all",1);
	message_vision(CYN"$N痛苦地捂住眼睛，直在地上打滚。\n"NOR,enemy);
	call_out ("recover",10, enemy);
	return 1;
}


int recover (object obj){
	if (!obj)	return 1;
	if (obj->query_temp("block_msg/all")>=1)
	    	obj->add_temp("block_msg/all", -1);
	tell_object(obj, HIG"慢慢慢慢的，你的眼睛开始可以分辨周围的事物了。\n" NOR);
	return 1;
}	
