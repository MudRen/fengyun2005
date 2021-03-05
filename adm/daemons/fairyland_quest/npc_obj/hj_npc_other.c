//                标准描述长度示例                                   |
// 幻境内人物  其他型
// 包括 教授技能、恢复体力、寻求宝物（有奖励）
// by naihe  2002-10-29  于茂名

#include <ansi.h>

inherit NPC;

#include "hj_settings/room_amount_hj.h"


string *colors=({
    ""HIR"",
    ""HIY"",
    ""HIG"",
    ""HIC"",
    ""HIW"",
    ""HIM"",
});
// 不要 HIB 颜色的精灵 ：）


int *move_time = ({ 5, 10, 2, 3 });
int *job_times = ({ 5, 10, 10, 3 });


int ask_find();

string me_find_name = "找东西";


void setme( int iii )
{
    string cl = colors[ random( sizeof(colors) ) ];

    if( iii == 99 ) iii = random(4);
    set("iii", iii ); // 此处 iii 为类型标记。

    set_name( cl+"小精灵"NOR, ({"jing ling", "jl", "ling" }) );
    set("msg",cl+"一阵幽香传来，只见旁边轻悠悠地飞过来一个小精灵。\n"NOR);

    set("job_times", job_times[ iii ] );

    set("long","这是一个常见于山野的小精灵，只有正常人的手掌大小，模样甚是可爱。\n");
    set("hj_game/npc","other");

    set("gender","女性");
    set("age",12+random(12));
    set("per",20+random(5));

    set("inquiry",([
        me_find_name : (: ask_find :),
        ]));

    set("no_refresh",1);

    remove_call_out("delete_me");
    remove_call_out("random_move");
    remove_call_out("random_teach");
    remove_call_out("random_heal");
    remove_call_out("random_drop");
    remove_call_out("random_find");

    call_out("do_all_start", 3);
}

void create()
{
    setme( 99 );
  setup();
}

void do_all_start()
{
    if( !environment(this_object()) ) return;

    call_out("delete_me", 240 + random( 60 ) );
    call_out("random_move", 1);

    switch( query("iii") )
    {
        case 0: call_out("random_teach",1); break;
        case 1: call_out("random_heal",1); break;
        case 2: call_out("random_drop",1); break;
        case 3: call_out("random_find",1); break;
    }
}


void delete_me()
{
    message_vision("$N左望望，右望望，忽地就不知飞向何处去了。\n",this_object());
    destruct(this_object());
}

int random_move()
{
    string *dirs=({
"east","west","south","north","northeast","northwest","southeast","southwest"
        });

    if(random(3) == 1 && living(this_object()))
        command(dirs[random(sizeof(dirs))]);

    remove_call_out("random_move");
    call_out("random_move", move_time[ query("iii") ] );
    return 1;
}

void random_teach()
{
    object *inv,target,ob=this_object();
    int i;
    string *skills_ids,*skills_names;

    if( query("job_times") < 1 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",10);
        return;
    }

    if(random(2) == 1)
    {
        inv = all_inventory(environment(ob));
        if(inv && sizeof(inv) > 0)
        {
            target = inv[random(sizeof(inv))];
            if(target->is_character() &&
                   target->query_temp("huanjing") == "start" &&
               living(target) && random(2) == 1)
            {

// 下面开始教这个玩家这项技能 :)

    skills_ids=({"hfzj","hyzj","llzj","ydzj","gszj","fhzj","dhzj","heal"});
    skills_names=({"呼风之技","唤雨之技","落雷之技",
    "引电之技","滚石之技","飞火之技","夺魂之技","恢复之技"});
    i=random(sizeof(skills_ids));

    if(!target->query_temp("hj_game_skills/"+skills_ids[i]))
    {
        command("whisper "+target->query("id")+" 我来教你如何运用「"+skills_names[i]+"」的窍门吧！");
        command("whisper "+target->query("id")+" 这样这样，那样那样，明白了吗？");
        command("smile "+target->query("id"));
        ob->add("job_times",-1);
        target->set_temp("hj_game_skills/"+skills_ids[i],skills_names[i]);
        target->set_temp("hj_game_damages/"+skills_ids[i],3+random(3));
        message_vision(CYN"$N"NOR+CYN"只觉得突然之间灵感骤至，已领悟了「"+skills_names[i]+"」！\n"NOR,target);
    }
    else
    {
        command("whisper "+target->query("id")+" 我来教你如何加强「"+skills_names[i]+"」威力的窍门吧！");
        command("whisper "+target->query("id")+" 这样这样，那样那样，明白了吗？");
        command("pat "+target->query("id"));
        ob->add("job_times",-1);
        if( target->query_temp("hj_game_damages/" + skills_ids[i] ) < 99 )
        {
        target->add_temp("hj_game_damages/"+skills_ids[i],2+random(2));
        message_vision(CYN"$N"NOR+CYN"仔细想着，似乎觉得自己「"+skills_names[i]+"」的修为又有所提升了。\n"NOR,target);
        if(target->query_temp("hj_game_damages/"+skills_ids[i]) > 99)
            target->set_temp("hj_game_damages/"+skills_ids[i], 99);
        }
        else
        message_vision( CYN"$N"NOR+CYN"哈哈大笑道：“我早已得知其中关窍，不必费心了。”\n"NOR,target);
    }
            }
        }
    }

    if(random(3) == 1) message_vision(CYN"$N"NOR+CYN"四处望了望，「啦啦啦」地哼起了什么歌儿来。\n"NOR,this_object());
    remove_call_out("random_teach");
    call_out("random_teach",10+random(11));
}


void random_heal()
{
    object *inv,target,ob=this_object();
    int hp,hp_max;

    if(query("job_times")<1)
    {
        remove_call_out("delete_me");
        call_out("delete_me",10);
        return;
    }

    inv = all_inventory(environment(ob));
    if(inv && sizeof(inv) > 0)
    {
        target = inv[random(sizeof(inv))];
        if(target->is_character() &&
               target->query_temp("huanjing") == "start" &&
           living(target) && target->query_temp("hj_hp") > 0 &&
           target->query_temp("hj_hp_max") > 0 )
        {

// 下面开始给这个玩家恢复气息

    if(target->query_temp("hj_hp") < (target->query_temp("hj_hp_max") *8/10) )
    {
        hp=target->query_temp("hj_hp");
        hp_max=target->query_temp("hj_hp_max");

        command("idle2 "+target->query("id"));
        message_vision("$n"NOR+CYN"对着$N"NOR+CYN"轻轻地念了句什么，只见$N"NOR+CYN"的脸色顿时大为好转！\n"NOR,target, ob );
        ob->add("job_times",-1);
        hp+=30+random(hp_max/10);
        if(hp>hp_max) hp = hp_max;
        target->set_temp("hj_hp",hp);
    }
        }
    }

    if( !random(3) )
        message_vision(CYN"$N"NOR+CYN"四处望了望，「嘻」地笑了一声。\n"NOR, ob);
    remove_call_out("random_heal");
    call_out("random_heal",5+random(6));
}

void random_drop()
{
    object guo, ob = this_object();

    if(query("job_times")<1)
    {
        remove_call_out("delete_me");
        call_out("delete_me",10);
        return;
    }

    if(random(3) == 1)
    {
        guo = new(__DIR__"hj_obj_other");
        guo->setme(0);
        guo->move(environment(this_object()));
        message_vision(CYN"$N"NOR+CYN"身上忽地掉下一颗小果子！\n"NOR, ob );
        this_object()->add("job_times",-1);
    }

    if(random(3) == 1) message_vision(CYN"$N"NOR+CYN"轻轻地唱道：“采果儿，采果儿，勤劳恳作干活儿。”\n"NOR, ob );
    remove_call_out("random_drop");
    call_out("random_drop",10+random(11) );
}

void random_find()
{
    int i;
    string *find_names,*find_ids;
    object ob = this_object();

    if(query("job_times")<1)
    {
        remove_call_out("delete_me");
        call_out("delete_me",10);
        return;
    }

    if(!query("me_find_id") && random(5) == 1)
    {

find_names=({"定向水晶","飞翔之石","脱离水晶","回归之镜","祈祷之石","召唤之盒",
"发呆之旗","驱逐之旗","寻人水晶","定位之仪",
"红色宝石","蓝色宝石","绿色宝石",
"呼风之石","唤雨之石","落雷之石","引电之石","滚石之石","飞火之石","夺魂之石","复活之石",
"青铜之剑","灵气之剑","白银之剑","盈动之剑","黄金之剑",
"耐力之剑","迅隐之剑","夺魂之剑","必胜之剑","狂风水晶",
"暴雨水晶","落雷水晶","引电水晶","滚石水晶","飞火水晶","夺魂水晶",
});

find_ids=({"dx shuijing","fx zhishi","tl shuijing","hg zhijing","qd zhishi","zh zhihe",
"fd zhiqi","qz zhiqi","xr shuijing","dw zhiyi",
"red baoshi","blue baoshi","green baoshi",
"hufeng shi","huanyu shi","luolei shi","yindian shi",
"gunshi shi","feihuo shi","duohun shi","fuhuo shi",
"qt jian","lq jian","by jian","yd jian","hj jian",
"nl jian","bj jian","dh jian","bs jian","kf sj",
"by sj","ll sj","yd sj","gs sj","fh sj","dh sj",
});

        i=random(sizeof(find_names));
        set("me_find_id",find_ids[i]);
        me_find_name = find_names[i];
        set("inquiry",([
            me_find_name : (: ask_find :),
            ]));
    }

    if(!query("me_find_id") && random(2) == 1)
message_vision(CYN"$N"NOR+CYN"轻轻地唱道：“我寻寻寻，我觅觅觅，怎么却不见我要找的东西？”\n"NOR, ob );

    else if(query("me_find_id") && random(2) == 1)
message_vision(CYN"$N"NOR+CYN"轻轻地唱道：“我寻寻寻，我觅觅觅，怎么却不见我要找的"+me_find_name+"？”\n"NOR, ob );

    remove_call_out("random_find");
    call_out("random_find",5+random(6));
}

int ask_find()
{
    object find,srl,me = this_player(), ob = this_object();

    if(!query("me_find_id") )
    {
        command("sing");
        return 1;
    }

    find=present(query("me_find_id"),me);
    if(!find)
    {
        command("say 我是要找它呀！如果有人能帮我找找，那该多好呀！");
        command("xixi");
        return 1;
    }
    if(!find->query("hj_game/obj"))
    {
        command("say 哎呀，你带着的这个不是真的啦！我要找那个真的呀！");
        command("giggle");
        return 1;
    }

    message_vision(CYN"$N"NOR+CYN"拿出一"+find->query("unit")+find->query("name")+NOR+CYN"递给$n"NOR+CYN"。\n"NOR, me, ob );
    destruct(find);
    command("wa "+me->query("id"));
    command("touch");
    srl=new(__DIR__"shenren_ling");
    srl->waiting_delete( 120+random(60) );
    message_vision("$n"NOR+CYN"拿出一"+srl->query("unit")+srl->query("name")+NOR+CYN"递给了$N"NOR+CYN"。\n"NOR, me, ob);
    srl->move(me);
    command("blush "+me->query("id"));
    delete("me_find_id");

    remove_call_out("random_find");
    call_out("random_find",10);
    return 1;
}
