#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石门");
        set("long", @LONG
地道的尽头是一扇石门。两旁的墙壁上各悬着一盏琉璃灯。琉璃灯中油半满，
点上灯大概可以维持两三日。灯光照亮了那扇石门。白石石门上面刻着奇怪的花纹，
那些花纹与鹦鹉楼中宋妈妈那间魔室门户上刻着的竟有些相似。惨绿色的花纹，灯
光中，闪耀着异样的寒芒。洞顶黑漆漆的，却似乎有什么东西在闪光。
LONG
        );
        set("exits", ([ 
		"westup":  __DIR__"andao2",
//		"south":  __DIR__"stoneroom",
	]));
        set("item_desc", ([
		"花纹":	"仔细辨认，石门上写的是西域的文字，--“宝库”。\n",
		"石门":	"仔细辨认，石门上写的是西域的文字，--“宝库”。\n",
		"door":	"仔细辨认，石门上写的是西域的文字，--“宝库”。\n",
		"洞顶":	"地道的顶壁竟然有几排方洞，暗黑的方洞中寒芒闪烁，一列一列的尽是锋利的枪尖。
千百支尖枪一齐落下，地道中的人走避不及便成刺猬。看来开门后得快速后退，才
能躲过这个机关。\n",
		"roof":	"地道的顶壁竟然有几排方洞，暗黑的方洞中寒芒闪烁，一列一列的尽是锋利的枪尖。
千百支尖枪一齐落下，地道中的人走避不及便成刺猬。看来开门后得快速后退，才
能躲过这个机关。\n",
	 ]));
	set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",-20);
	set("map","taiping");
	setup();
}

void init()
{
       	add_action("do_push", "push");
       	add_action("do_open","open");
}

int	do_open(string arg){
	if (arg == "door" || arg=="石门" || arg=="门"){
		tell_object(this_player(),"石门紧紧闭着，要用力推一下才行。\n");
		return 1;
	}
}

void close_passage()
{
        object room;
        message("vision", "石门无声无息地又转了回来，遮住了暗道。\n", this_object() );
        set("door_opening",0);
        delete("exits/south");
}

int do_push(string arg)
{
        object obj, room, me;
        me=this_player();
        if(!arg || (arg != "石门" && arg != "门" && arg !="door")) {
                return 0;
        }
	if (query("exits/south"))
		return notify_fail("石门已经打开了。\n");
	if (me->query_str()<=60)
		return notify_fail("你一掌推去，石门纹丝不动。\n");
	if (query("door_opening"))
		return notify_fail("石门已经在移动了。\n");
	
	message_vision(YEL"$N双臂托住石门，猛可往上一翻，暴喝一声，道：“上！”\n"NOR,me);
	message_vision(YEL"慢慢地慢慢地，石门开始向上移动。。。。\n"NOR,me);
	set("door_opening",5);
	call_out("arrow_trap", 6);
        return 1;
}


void open_passage() {
	message("vision","吱吱嘎嘎一阵响动后，石门终于打开了。\n",this_object());
	set("exits/south",__DIR__"stoneroom");	
	call_out("close_passage", 20);
}

void arrow_trap() {
	object *inv;
	int i;
	message("vision",WHT"\n猛然间耳畔利刃划空之声大作，洞顶上竟然射出了数十支短枪。\n\n"NOR,this_object());
	inv=all_inventory(this_object());
	for (i=0;i<sizeof(inv);i++) {
		if (!inv[i]->is_character()|| inv[i]->is_corpse()) continue;
		message_vision(WHT"$N躲避不及，被短枪穿了个透心凉。。。\n"NOR,inv[i]);
		inv[i]->set_temp("last_damage_from","中机关乱枪穿身而亡。\n");
		inv[i]->receive_wound("kee",12000);
		COMBAT_D->report_status(inv[i]);
	}
	call_out("open_passage", 4);
}

void reset()
{
        ::reset();
        delete("exits/south");
	set("door_opening",0);
}


