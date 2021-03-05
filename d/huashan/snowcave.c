#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"雪花洞"NOR);
        set("long", @LONG
崖壁上是一个人工凿刻的山洞，洞不大，没有人知道当初为什么要凿这山洞。
洞内凉风习习，即使在最炎热的夏季，只要一入洞口，暑意尽消。向外望去，青柯
坪尽在眼内；向上看，洞顶石纹斑点光彩晶莹，似雪花向下飘落。
LONG
        );
    set("exits", ([ 
  		"southwest" : __DIR__"qingke",
	]));

	set("objects", ([
		__DIR__"npc/bailong" : 1,
		__DIR__"npc/fang": 1,
	]) );  
	set("doing_rescue", 0);
    set("indoors", "huashan");
	set("no_lu_letter",1);
	set("coor/x",-11);
	set("coor/y",-28);
	set("coor/z",0);
	setup();
}

void init(){
	if (REWARD_D->riddle_check(this_player(),"华山救美"))
	{
//	if(this_player()->query("marks/初见方少璧")) {
		call_out("save_me", 1, this_player());
	}
	add_action("do_rescue", "rescue");
}

void save_me(object me){
	object sun, fang;
	sun = present("sun yuanchao", this_object());
	fang = present("fang girl", this_object());
	if(objectp(sun) && objectp(fang) && !query("doing_rescue")) {
		message_vision("\n$N原本黯然忧伤的眼神看到$n猛然一亮，继而闪过一丝错综复杂的光芒。\n", fang, me);
		message_vision("$N想跑到$n身前却被孙远超所阻，只得叫道：“救我！”\n哀怨的声音让人心生不忍。\n", fang, me);
		tell_object(me, "（ｒｅｓｃｕｅ　ｎｏ／ｙｅｓ）\n", me);
		me->set_temp("marks/hs_in_rescue",1);
		set("doing_rescue", 1);
//		call_out("reluctant", 40, me); // Silly, what if I killed sun but didn't say yes ?
	}
}

int do_rescue(string arg){
	object me;
	me = this_player();
	if(!arg || (arg != "yes" && arg != "no")){
		return 0;
	}	
	if (!query("doing_rescue"))		return 0;
	if (!me->query_temp("marks/hs_in_rescue"))	return 0;
		
	if(arg == "yes")
	{
		remove_call_out("reluctant");
        	me->ccommand("kill sun yuanchao");
        	me->delete_temp("marks/hs_in_rescue");
	} else if(arg == "no"){
		remove_call_out("reluctant");
		message("vision", me->name() + "眼光略一扫过，脸上毫无表情。\n", environment(me), me);
		tell_object(me, "你决定事不关己，还是不要插手的好。\n");
		me->delete_temp("marks/hs_in_rescue");
		me->delete("riddle/华山救美");
	}
	return 1;
}

/*
void reluctant(object me){
	if(!interactive(me) || environment(me) != this_object())
	{
		return;
	}
	message_vision("少女眼神中充满了失望，默默的低下了头。\n", me);
	if (!REWARD_D->check_m_success(me,"华山救美"))			
	{
		REWARD_D->riddle_done(me,"华山救美",-100,2);
	}
	return;
}*/

void check_rescue(object me){
	object fang;
	fang = present("fang girl", this_object());
	if(objectp(fang)){
		call_out("rescued", 2, me);
	}
}

void rescued(object me){
	object fang;
	if(!me || !interactive(me) || environment(me) != this_object()) {
		return;
	}
	fang = present("fang girl", this_object());
	if(objectp(fang)){
		if(me->query("age") < 25){
			message_vision("$N对着$n浅浅一笑，一朵红云飞上面颊：“多谢着位大侠救命之恩。”\n", fang, me);
			message_vision("言毕少女转身向洞外离去，走到洞口，少女似有心又似无意的转头看了$N一眼。\n", me);
		} else {
			message_vision("$N道：“多谢这位大侠救命之恩。”\n", fang, me);
			message_vision("言毕少女转身向洞外离去。\n", me);
		}
		
		if (REWARD_D->riddle_check(me,"华山救美"))
		{
			if (!REWARD_D->check_m_success(me,"华山救美"))			
			{
				REWARD_D->riddle_done(me,"华山救美",100,1);
			}
			if(!REWARD_D->imbue_check(me,"华山救美")){
				me->start_busy(3);
				call_out("imbue_event", 2, me);
			}
		} else
			me->delete("riddle/华山救美");
		destruct(fang);
	}
}

int imbue_event(object me){
	object weapon, ob, *inv, obj;
	string prop;
	int i;
	mapping data;
	
	if(!interactive(me) || environment(me) != this_object()) {
		return 0;
	}

	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(HIW"\n一点白色的荧光从洞顶缓缓飘落，犹如冬季的雪花。\n"NOR, me);
		} else {
			message_vision(HIW"\n一点白色的荧光从洞顶缓缓飘落在$N的" + obj->name() +
					HIW"上，转眼间光点灭去。\n"NOR, me);
		}
	}else{
		message_vision(HIW"\n一点白色的荧光从洞顶缓缓飘落在$N的" + weapon->name() + HIW"上。。。\n"NOR,
				me);
		message_vision(HIW"荧光刚一接触" + weapon->name()+ HIW"一道耀眼的光芒乍起，迅速一切又回归平静。\n"NOR, me);
	}
	
	data = ([
		"name":		"华山救美",
		"target":	me,
		"att_1":	"kar",
		"att_1c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);	
	return 1;
}
