
inherit ROOM;

void create()
{
        set("short", "骆驼口");
        set("long", @LONG
骆驼口不但有卖骆驼,还能雇到赶骆驼的人。沙漠里有打劫的匪帮、致命的毒虫、
在转眼间盖没一个村落的沙暴，对没有经验的人来说，沙漠是个可怕的有去无回的
地方，但只要请到这里赶骆驼的汉子，就一定能安全准时地到达你的目的地。
LONG
        );
        set("exits", ([ 
 		"west": __DIR__"fair2",

	]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/xiaopan": 1,
                __DIR__"npc/shituo": 1,
        ]) );
	set("coor/x",-1025);
	set("coor/y",-10);
	set("coor/z",0);
	set("route_clear",1);
	set("bandit_name","老云寨");
	setup();

}

void init_scenery()
{
     call_out("bandit_out",1);
}

void bandit_out() {
    string *bandit = ({"老云寨","蝙蝠岛","黑松堡" });
	string band;
	
	if (query("route_clear")) {
		band = bandit[random(sizeof(bandit))];
		set("route_clear",0);
		set("bandit_name",band);
		//CHANNEL_D->do_sys_channel("info","往返沙漠的骆驼队遭蒙面匪徒截杀，无一生还！"); //禁止个别玩家robot故决定不提示
	}
}


int go_out_1(object me, int stage) {
	object room;
	string *route = ({AREA_QUICKSAND"saikou", AREA_QUICKSAND"saiwai2", 
				AREA_QUICKSAND"yangguan", AREA_ZANGBEI"kunlun1",
				AREA_TAIPING"mroad1", AREA_TAIPING"yizhan", 
				AREA_TAIPING"stable" });
	string *dir = ({ "西","西","西","西","南","东","北" });
	
	if (!me || me->is_ghost())	return 1;
		
	if (me->is_ghost()||me->is_fighting()) {
		tell_object(me,"你从骆驼上跳了下来。\n");
		me->stop_busy();
		me->delete_temp("ride");
		return 1;
	}
	
	room=find_object(route[stage]);
	if(!objectp(room)) room = load_object(route[stage]);
        message_vision("$N骑着骆驼向"+dir[stage]+"离开。\n",me);
        me->move(route[stage]);
        message_vision("$N骑着骆驼走了过来。\n",me); 
//	write ("stage is "+stage+" route is "+sizeof(route)+"\n");
	stage++;
	if (stage == sizeof(route)) {
		message_vision("赶驼人一声吆喝：“到了！”\n",me);
		message_vision("$N从骆驼背上一跃而下。\n",me);
		me->delete_temp("ride");
		me->stop_busy();
		return 1;
	}
	call_out("go_out_1",2,me, stage);
    return 1;
}


