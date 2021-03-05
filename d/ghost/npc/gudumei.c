#include <ansi.h>
inherit NPC;

void create()
{
        set_name("孤独美", ({ "gu du mei", "gu du" }) );
        set("nickname", "六亲不认");
        set("title", "独行大盗");
        set("gender", "男性");
        set("age", 56);
        set("no_arrest",1);
        set("long",	"一个两鬓斑白的人，衰老、憔悴、疲倦、悲伤而恐惧。\n");
        setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/sword")->wield();
}

void init()
{
        object          me;
		object          leader;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {       	 	
			remove_call_out("greeting");
			call_out("greeting", 1, me);
			add_action("do_agree", "agree");
        }
}

int do_agree(string arg)
{
		object		me;			
		string *route1, *route2, route, route_c;
		int *num, i, j;
		
		num = allocate(4);
		me = this_player();
		route1 = ({ "e", "n", "w", "s" });
		route2 = ({ "东","北","西", "南" });
		
        tell_object(me, "孤独美道：好，你先动身，我在你身后暗处跟随。\n");
        
        route = "";
    	route_c = "";
    	    
        for (i = 0; i<4; i++ )
        {
        	num[i] = 1+ random(6);
        	for (j=0;j< num[i] ;j++)
        	{
        		route = route + route1[i];
        	}
        	route_c = route_c + route2[i]+ chinese_number(num[i]);
        }
               
//        tell_object(me, " string is " + route + "\n");
        tell_object(me, "东行一步，然后" + route_c + "，切记切记！\n");
        me->set_temp("marks/gudumei_walk","");
        me->set_temp("marks/gudumei_route",route);
        return 1;
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	
	tell_object(ob, YEL "孤独美的喉结上下滚动着，充满了恐惧的眼里露出了一丝希望，喘息着道：\n"NOR);
	tell_object(ob,YEL "你．．．是谁？帮我！没有我，你走不出的！(agree to help)\n"NOR);
	return;
}