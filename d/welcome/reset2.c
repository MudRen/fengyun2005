// Silencer@fy4 workgroup

// 属性重置，存盘

// 其他属性清零、技能清零，存盘

// 补回基本的技能、书籍



inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW"技能分配房间"NOR);
	set("long", @LONG
在这间屋子里，将把你所有学过的技能清零，同时清除因此而提高的属性点，
为了减轻大家重新学习的负担，一部分可以读到的基本技能将由系统自动提供。
LONG
	);
	set("exits", ([
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",700);
	set("no_magic",1);
	set("no_fight",1);
	set("valid_startroom", 1);
	setup();
}

int init(){
	object me;
	string *att = ({"int","cps","agi","str","con","kar"});
	string *att_c = ({ "才智","定力","速度","力量","体质","运气" });
	int i;
	mapping data;
	string *item;
	
	// 重新分配属性点
	me = this_player();
	if (me->query("id") != "tester")	return 1;
	
	tell_object(me,"==========================================\n");
	for (i=0;i<sizeof(att);i++){
		tell_object(me,"你从学习中提高了"+ me->query("improve/"+ att[i])+ "点"+ att_c[i]+"\n");		
//		me->add(att[0],-me->query("improve/"+att[i]));
	}
	
	tell_object(me,"\n这部分属性点的增加恢复到初始值。\n\n");
	tell_object(me,"==========================================\n");


	// 重置潜能点	
	tell_object(me,"你所用去的"+ me->query("learned_points")+"点潜能已经被全部返回，
现有潜能"+ me->query("potential")+"点。\n");
	tell_object(me,"==========================================\n");

//	me->delete("annie/skill_cost");
//	me->delete("learned_points");
	
	// 清 ENable	
//	me->reset_skill_map();
	
	// 清技能
//	me->reset_skill();
		
	// 清learned	
//	me->reset_learned();
		
	me->save();

	// 重置技能

	return 1;
		
}

int improve_player(object me)
{
	// 才智
	me->set_skill("literate",60);
	me->add("improve/int",2);
	me->add("int",2);

}

