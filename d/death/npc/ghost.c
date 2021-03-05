// ghost.c

inherit NPC;

void create()
{
        set_name("孤魂野鬼", ({ "wandering ghost", "ghost" }) );        
        set("age", random(65));
        set("str", 24);
        set("cor", 26);

        set_temp("apply/attack", 10);
        set_temp("apply/armor", 10);
        
        
		
		set("inquiry", ([
          	"明烟草" : 	"action孤魂野鬼叽叽喳喳一阵乱叫，可惜你什么也听不懂。\n",
      	]) );
        
        setup();
        carry_object("/obj/armor/ghost_cloth")->wear();
}

int is_ghost() { return 1; }



