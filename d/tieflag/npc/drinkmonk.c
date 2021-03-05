// drinkmonk.c
#include <ansi.h>
inherit NPC;

int go_in();
void create()
{
    	set_name("酒肉和尚",({"drink monk","monk"}));
    	set("long","这是一个僧不僧俗不俗，满头乱发的怪人\n");
    	set("gender","男性");
    	set("no_arrest",1);
    	set("age",42);

    	set("combat_exp",1000000);
    
    	set_skill("force",100);
    	set_skill("lotusforce",100);
    	set_skill("unarmed",100);
    	set_skill("parry",150);
    	set_skill("dodge",150);
    	set_skill("dabei-strike",150);
    	set_skill("nodust-steps",120);
    	
    	map_skill("unarmed","dabei-strike");
    	map_skill("dodge","nodust-steps");
    	map_skill("force","lotusforce");
    
 	set_temp("apply/attack",150);
	set_temp("apply/dodge",100);
    
    	set("attitude", "heroism");
    	set("inquiry",([
        	  "meat": (: go_in :),
          	"肉"  : (: go_in :) ,
          	"碧落赋" : "此赋本乃称颂苍穹碧落，但现有人用之形容武林中数大奇人。\n",
           ])   );
    	set("chat_chance",1);     
    	set("chat_msg",({
        	  "酒肉和尚喃喃吟道：“尔其动也，风雨如晦，雷电共作，尔其静也，体象皓镜，星开碧落！”\n",
          	"酒肉和尚掀开锅盖看了一眼\n",
          }) );

    	setup();
    	carry_object(__DIR__"obj/cloth_d")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    say ("酒肉和尚说道：“过来坐一坐吧”\n");
    return 1;
}


int go_in()
{
    object killer, *enemy;
    if ( is_fighting() ) {
    	enemy = query_enemy();
    	for ( int i =0; i<sizeof(enemy); i ) {
    		if (environment(enemy[i]) == environment(this_object())) {
    			killer = enemy [i];
    			break;
    		}
    	}
	message_vision(HIY"$N一边打一边喊：“现在不吃肉，看洒家放倒这个" + RANK_D->query_rude(killer)
		+"再吃肉！”\n"NOR,this_object());     	
    	return 1;
    }

    command("say 你不说我倒忘了，待洒家把这碗肉送去再来说话。");
    message_vision("$N双手捧着肉碗，走到小门门口。\n",this_object());
    command("cat");
    message_vision("$N将门户轻轻推开一线，侧身走了进去。\n",this_object());
    this_player()->start_busy(1); 
    call_out("disap",1);
 
    return 1;
}

void disap()
{
	object room;
   	message_vision("忽然屋内“啊呀”一声惊呼，“呛啷”一声碎响，显见那肉碗也落在地上。\n",this_object());
	room=find_object(AREA_TIEFLAG"maoroom1");
	if(!objectp(room))
	room = load_object(AREA_TIEFLAG"maoroom1");
	this_object()->move(room);
                call_out("greeting2", 2);
}


int greeting2()
{

    say ("酒肉和尚说道：“她此番逃将出去，乱子就要惹大了。洒家无论如何也要抓她回来。”\n");
    say ("话声方了，便听屋里扑通一声，似乎有什么东西掉了下去。\n");
    destruct( this_object());
    return 1;
}

