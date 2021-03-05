// yinbin.c
inherit NPC;
void create()
{
    set_name("阴宾",({"yin bin","yin","bin"}));
    set("long","她面上蒙着轻红罗纱，隐约间露出面容轮廓，当真美得惊人，宛如烟
笼芍药，雾里看花。\n");
    set("gender","女性");
    set("age",42);
    set("per",35);
    set("combat_exp",50000);

    set_skill("nine-moon-force",20);
    set_skill("unarmed",100);
    set_skill("nine-moon-claw",40);
    set_skill("nine-moon-steps",40);
    set_skill("parry",50);
    set_skill("dodge",50);

    map_skill("force","nine-moon-force");
    map_skill("unarmed","nine-moon-claw");
    map_skill("dodge","nine-moon-steps");
    set("attitude", "friendly");
    set("chat_chance",5);     
    set("chat_msg",({
          "阴宾笑道：“你可要我掀开面纱让你看看么？”\n",
          }) );

    setup();
    carry_object(AREA_TIEFLAG"npc/obj/redcloth")->wear();
    carry_object(AREA_TIEFLAG"npc/obj/redjin")->wear();
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
 
    command("lovelook");
    message_vision("阴宾眼波四转，笑道：“他只当我自地道走了，可我偏偏留在这儿。”\n",this_object());
    
    if( !me || environment(me) != environment() ) {
    	command("say 我也该走了，外面有人接我呢！");
	    message_vision("$N回眸一笑，走了出去。\n",this_object());
	    destruct(this_object());
    	return 1; 
    }
    call_out("leave",30,me);
    return 1;
} 

void leave(object me)
{
    if (is_fighting()) {
    	call_out("leave",30,me);
    	return;
    }  	
    command("say 我也该走了，外面有人接我呢！");
	message_vision("$N回眸一笑，走了出去。\n",this_object());      
    
    if (me && environment(me) == environment())
	      me->set_temp("mark/阴宾",1);
    destruct(this_object());
}
