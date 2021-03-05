// TIE@FY3
#include <ansi.h>
#include <login.h>
#define MAX_EXP 5000
inherit NPC;
string *death_msg = ({
	HIW "判官那锐利的目光象把刀一样在你身上扫来扫去。\n\n"NOR,
	HIW "判官翻了翻勾魂簿，叹道：又一个夭折的短命鬼。\n\n"NOR,
	HIW "判官合上簿子说道：阳寿未尽？罢了罢了，你走吧。\n\n"NOR,
	HIW "一股阴冷的浓雾突然出现，很快地包围了你。\n\n"NOR,
});

string *revive_loc= ({
    	AREA_FY"church",
    	AREA_GUANWAI"tower",
});

void create()
{
    	set_name("朱笔判官", ({ "panguan", "ghost judge" }) );
    	set("nickname", HIR"善有善报、恶有恶报"NOR);
    	set("long", "阎王身边的朱笔判官，专勾画天下人的生死。\n");
    	set("attitude", "peaceful");
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	HIW"判官喝道：牛头，马面何在？\n"NOR,
        	HIW "判官那锐利的目光象把刀一样在你身上扫来扫去。\n\n"NOR,
        	HIW "判官翻了翻勾魂簿，叹道：又一个夭折的短命鬼。\n\n"NOR,
        	HIW "判官合上簿子说道：阳寿未尽？罢了罢了，你走吧。\n\n"NOR,
    	}) );
    	set("age", 217);
    	set("combat_exp", 20000000);
    	set("no_arrest", 1);
    	
    	setup();
    	carry_object("/obj/armor/ghost_cloth")->wear();
}

/*
void init()
{
    	::init();
    	if(!previous_object() || !userp(previous_object()) ){
        	return;
    	}
    	call_out( "death_stage", 3, previous_object(), 0 );
}


void death_stage(object ob, int stage){
	object cloth;
    	if( !ob || !present(ob)) return;
    	
    	
    	
	tell_object(ob, death_msg[stage]);
    	if( ++stage < sizeof(death_msg) ) {
        	call_out( "death_stage", 3, ob, stage );
        	return;
    	} else if (ob->is_ghost())
            	ob->reincarnate();
	cloth = new("/obj/armor/cloth");
	if(objectp(cloth)){
		cloth->move(ob);
		cloth->wear();
    	}
    	ob->move(revive_loc[random(sizeof(revive_loc))]);
    	ob->set("startroom", base_name(environment(ob)));
    	message("vision",
           		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
            		"很久了，只是你一直没发觉。\n", environment(ob), ob);
}

*/


