inherit NPC;
#include <ansi.h>
int random_action();
int give_xinchungift();

void create()
{
        set_name(HIB "新春礼物大使" NOR, ({ "giftmaster" }) );

        set("gender", "男性");
    set("nickname", HIW"风云2005QQ群：132539787，欢迎加入"NOR);
        set("age", 92);
        set("long",
                HIC"    新手礼物大使是也！找他要礼物吧！
                \n         ask giftmaster about xinchungift 
                \n"NOR);
        set("attitude", "peaceful");
        set("str", 26);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("per", 50);

         set("chat_chance", 5);
        set("chat_msg", ({
                
                HIC"礼物大使说道：现在可以到我这里领取新春礼物(ask giftmaster about xinchungift) 。\n"NOR  ,
             
        }) );
				set("inquiry",      ([
        
        "xinchungift" : (: give_xinchungift :),
               ]) );
        
        
        set("combat_exp", 10000);
        set("score", 0);
        setup();
        
}


int accept_fight(object me)
{       object who=this_player();
        command("say 老身久不动手，武艺早已生疏，怎是" + RANK_D->query_respect(who)+ "的对手？");
        return 0;
}

int give_xinchungift()
{
        object gift;
        if (this_player()->query("combat_exp")<5000)
        {
                command("shake "+this_player()->query("id"));
                command("say "+this_player()->name()+"你的经验不够，我不能给你。");
                return 1;
        }
        if (this_player()->query("cont_quest")<5)
        {
                command("shake "+this_player()->query("id"));
                command("say "+this_player()->name()+",连续做5个任务，就可以领一个礼包。");

                return 1;
        }
        gift = new("/d/wiz/obj/xinchungift");
        gift -> move(this_player());
        message_vision("$N"NOR+"递给$n一个"+gift->query("name")+"。\n"NOR,this_object(),this_player());
        this_player()->set("cont_quest",0);
        return 1;
}

int attack()
{
        
     command("say 算了，不打了，礼物还没发完呢!");
     this_object()->remove_all_killer();
     return 0;

} 
