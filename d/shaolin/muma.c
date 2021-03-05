// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "木马道");
        set("long", @LONG
很奇怪，没想到刚出了木人巷又会碰上这玩艺，你居然站在一个坑中，四周的
坡子上全是木马，向你奔来，机关之学，居然精密如斯，如果不及时躲开，别说出
少林，只怕性命也是难保。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"houmen",
]));
        set("outdoors", "shaolin");
	set("no_magic",1);
	set("coor/x",0);
	set("coor/y",140);
	set("coor/z",20);
	setup();
}

void init()
{
        delete("exits");
        if(userp(this_player()))	{
        	remove_call_out("attack");
        	call_out("attack",1+random(2),this_player());
        }
}


int attack(object me)
{
	object muren;
	if (!me)	return 1;
		
	muren= new(__DIR__"npc/horse");
	muren->set("combat_exp",3000000 + 20000*random(100));
	muren->set_temp("apply/damage",500+50*random(10));
	muren->move(this_object());

	if (environment(me)==this_object())
		COMBAT_D->do_attack(muren,me);
	me->set_temp("last_damage_from","力闯少林木马巷未遂，被木马踢死了。");
	
	if(present(me,this_object()) && random(9)){
		destruct(muren);
		call_out("attack",1+random(2),me);
	}
	else	{
		destruct(muren);
		set("exits/north", AREA_SONGSHAN"houmen");
		me->delete_temp("last_damage_from");
	}
	
}

