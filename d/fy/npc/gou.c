inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("赛伯牙", ({ "sai boya","sai" }) );
        set("gender", "男性" );
        set("age", 31);
        set("title", CYN"附庸风雅"NOR);
        set("long","这位老板本身不谙音律，却偏生喜欢附庸风雅，曾被俞琴
所嘲笑，为雪耻竟变卖先祖遗产在风云城中开起琴行。\n");
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([  
                "/obj/music/qixianqin"          : 40,
                "/obj/music/yaoqin"                     : 10,
                "/obj/music/erhu"                       : 30,
                "/d/biancheng/npc/obj/erhu"     : 40,
                "/obj/music/music_bihai":		40,
                "/obj/music/music_qingxin":		40,
                "/obj/music/music_shimian":		40,
                "/obj/music/music_xiaoxiang":	40,
        ]) );
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
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
        if (!random(4))
                message_vision("$N摇头晃脑的看着手中的一本曲谱，却没发现他把书拿反了。\n",this_object(),ob);
        else if (!random(4))
                message_vision("$N面色严肃的对$n道：琴有五韵，称作金、木、水、火、土，你可知道？\n",this_object(),ob);
        else if (!random(4))
                message_vision("$N从鼻孔里哼了一声说：俞琴算什么东西？我表姨丈家胖公子对音乐可比他精熟多了。\n",this_object(),ob);
        else if (!random(40) && !query("sec"))
        {
                set("sec",1);
                tell_object(ob,"赛伯牙附在你的耳边，小声说道：＂告诉你一个秘密，传说白云仙子\n的玉壶冰，是个比＇看起来＇好得多的古琴。＂");
        message("vision", "赛伯牙贴在"+ob->name()+"耳边悄声说了几句话。\n", environment(ob), ob);
        }
        return;
}

void reset()
{
        set("vendor_goods", ([
                "/obj/music/qixianqin"          : 40,
                "/obj/music/yaoqin"             : 10,
                "/obj/music/erhu"               : 30,
                "/d/biancheng/npc/obj/erhu"     : 40,
                "/obj/music/music_bihai":		40,
                "/obj/music/music_qingxin":		40,
                "/obj/music/music_shimian":		40,
                "/obj/music/music_xiaoxiang":	40,
        ]) );
}

