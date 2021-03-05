#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("珠宝商", ({ "jade seller", "seller" }) );
        set("gender", "男性" );
        set("age", 49);
        set("long", "这是一位饱经风霜的店掌柜。\n");
        set("combat_exp", 700000);
	
		set("max_kee", 2400);
		set("kee",2400);
	
		set("str", 300);
        set("attitude", "friendly");

		set("inquiry", ([
        	"古董三":	"古董三，古董三，原名叫英穷死，就是那个有名的探宝大王了。\n",
    	]) );
		        
        set_skill("blade", 130);
        set_skill("shortsong-blade", 100);
        set_skill("fall-steps", 130);
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set_skill("move",100);
        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");
        map_skill("move","fall-steps");
        
        set("vendor_goods", ([
                __DIR__"obj/jade1":12,
                __DIR__"obj/jade2":12,
                __DIR__"obj/jade3":12,
                __DIR__"obj/jade4":12,
				BOOKS"skill/buddhism_50b":12,
				"/obj/medicine/snake_drug":12,
				__DIR__"obj/amber1":3,
        ]) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/jadeblade")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买玉挡灾吗？ \n");
                        break;
                case 1:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉是吉祥之物，大漠无情，还是买一块挡灾吧。 \n");
                        break;

        }
}


void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/jade1":12,
                __DIR__"obj/jade2":12,
                __DIR__"obj/jade3":12,
                __DIR__"obj/jade4":12,
		__DIR__"obj/jademonk":12,
		"/obj/medicine/snake_drug":12,
		__DIR__"obj/amber1":3,
        ]) );
}



int accept_object( object who, object item){
		
		if (item->query("name") == HIM"紫晶宝石"NOR && item->query("jile")==1){
			if (REWARD_D->riddle_check(who,"紫晶之谜")==2 
				|| REWARD_D->riddle_check(who,"紫晶之谜/珠宝商")) {
				command("shake");
				command("say 你还是另找高人吧。");
				return 0;
			}
			
			message_vision(CYN"$N拿起"+item->query("name")+NOR+CYN"掂了几下，又拿出个镜片端详片刻，眉头紧锁。\n"NOR, this_object());
			command("say 前些日子好象有人从我这里经过，带了这么块玉石。");
			command("say 不过，这紫玉芯灰色暗，没什么太大价值。");
			command("shake");
			REWARD_D->riddle_set(who,"紫晶之谜/珠宝商",1);
			
			if (sizeof(who->query("riddle/紫晶之谜"))==4) {
				tell_object(who, CYN"\n"+name()+CYN"说：只有一个人会知道这块宝石的来历，他的名字叫古董三。
据说此人自三岁起就跟着他老爹在古墓里打转，这黑道白道上流转的宝物，
没有他不知道来历的，他一定知道这宝石的底细。\n");
				REWARD_D->riddle_set(who,"紫晶之谜",2);
			}
			
			return 0;
		}
			
		if (item->query("thief_obj")){
			command("say 小店不收来历不明之物。");
			return 0;
		}
				
}