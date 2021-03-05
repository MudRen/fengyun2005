#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "神秘冰河");
        set("long", @LONG
阳光下的冰河，看起来辉煌壮观。冰结十丈，坚如钢铁。这里离河岸很近，冰的
颜色却好象比别处还要深暗些。一段枯树露在河面上，想必是开始封江的时候倒下来
的。枯枝也不知被谁削平了，树干却还有一小半露在河面外。
LONG
        );
        set("exits", ([ 
  			"northeast" : __DIR__"street3",
		]));
        set("outdoors", "laowu");

	set("coor/x",28);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_zha", "bomb");
}

int do_zha()
{
	object me, *inv;
	int i;
	object exp;
	object con,item;
	me = this_player();
	inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
     {			
		if( inv[i]->query("explosive"))
			exp = inv[i];
	}
	if( !exp) 
	{
		tell_object(me,"你没有引爆的东西．\n");
		return 1;
	}

	if (exp->query("explosive")<2)
	{
		message_vision(HIR"$N点燃了手中的"+exp->name()+ HIR"．．．
听见“轰”的一声，河面上炸出了一个浅浅的凹坑。\n\n"NOR, me);
		tell_object(me, WHT"这火药看来威力太差。\n");
		destruct(exp);
		return 1;
	}
	
	message_vision(HIR"$N点燃了手中的"+exp->name()+ HIR"．．．
听见“轰”的一声大震，千万点碎冰飞激而起，夹带着枯树的碎片，花雨般滚落河面。\n\n"NOR, me, exp);
	destruct(exp);

	if ( (REWARD_D->riddle_check( me,"计取罗刹") != 3
			&& REWARD_D->riddle_check( me,"计取罗刹") != 4))
		return 1;
	message_vision(WHT"有一样黑黝黝的东西被震得往冰河下飞了起来，随着碎木冰块
一起落下“当”的一声，落在河面上。\n\n"NOR, me);
	
	con = new(__DIR__"obj/seal");
	item = new(__DIR__"obj/jadepai");
	if( con && item){
		item->move(con);
		con->move(this_object());
		REWARD_D->riddle_set( me, "计取罗刹", 4);
	}
	return 1;
}
