inherit ROOM;
#include <ansi.h>

int refresh_skill(object xiaodie,object me);

void create()

{
        set("short", "星星小室");
        set("long", @LONG
星星小室很静，在这儿你什么也不用想，也不需要说一句话，只要静静地享受
着这分沉默的乐趣。一个人若不懂得享受沉默，他就不能算是个真正会说话的人，
因为真正令人欢愉的言语，只有那些能领悟沉默的人才能说出来，真正沉醉在爱情
里的伴侣，只需要用眼神，用心来交谈。
LONG
    );
        set("exits", ([ 
		"north": __DIR__"star_room1",
	]));
        
        set("objects", ([
		__DIR__"npc/xiaodie":	1,
	]) );
        
        set("item_desc", ([
    		
	]) );
	set("no_fly",1);
	set("no_fight",1);
        set("coor/x",-1690);
        set("coor/y",630);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

/*
void init() {
	object me;
	if( interactive(me = this_player())) {
		refresh_skill(this_object(),this_player());
	}
}


int refresh_skill(object xiaodie,object me) {
	
	string *my_skill,*x_skill;
	int i;
	
	
	xiaodie=present("xiao die",this_object());
	if (!xiaodie) {
		xiaodie=new(__DIR__"npc/xiaodie");
		xiaodie->move(this_object());
	}
		
	// delete all xiaodie's skills
	if (xiaodie->query_skills())
		x_skill = keys(xiaodie->query_skills());
	if (sizeof(x_skill)>0) {
		for (i=0;i<sizeof(x_skill);i++) {
			xiaodie->delete_skill(x_skill[i]);
//			tell_object(me,"小蝶放弃了"+SKILL_D(x_skill[i])->name()+"。\n");
		}
	}
	xiaodie->delete("spouse");
	
	// setup xiaodie's skill according to guest's mark
	if (me->query("xiaodie")) {
		my_skill=keys(me->query("xiaodie"));
		if (sizeof(my_skill)>0) {
			for (i=0;i<sizeof(my_skill);i++)
				xiaodie->set_skill(my_skill[i],me->query("xiaodie/"+my_skill[i]));
		}
	}
	
	// set xiaodie's learn mark
	
	xiaodie->set("spouse",me);
	return 1;
}*/