// for feng_npc.c yu_npc.c lei_npc.c dian_npc.c

string *songs3=({
    "亲爱的朋友",
    "你可曾听说过，在远古的时候",
    "曾有过的古老国度的故事？",
    "那里有着各样的神奇的宝物",
    "也有着勤劳而善良的人们",
    "在我所在的地方，",
    me_guodu,
    baowu_name+"、"+baowu_other1+"和"+baowu_other2,
    "将能组成我们最为之着迷的",
    "国之灵物。",
    "我亲爱的朋友",
    "如果你能寻得它们",
    "你也将能够见到那往日的",
    "神秘国度的神秘之光。",
});

int ask_all();
int ask_baowu();

int singing=0;

void sing_song();
int i=0;

string *songs;
object baowu;

void wait_singsong();

string *gem_names=({
    "蛮野族宝物",
    "猛力族宝物",
    "矮妖族宝物",
    "山怪族宝物",
    "巨人族宝物",
});

string *gem_ids=({
    "manye baowu",
    "mengli baowu",
    "aiyao baowu",
    "shanguai baowu",
    "juren baowu",
});



#include "hj_settings/obj_list.h"
#include "hj_settings/room_amount_hj.h"



void create()
{
    set_name("臣民",({"chen min"}));
    set("long","这个人来自古老的"+me_guodu+"，竟不知是人是鬼是神是仙。\n");
    if(random(2) == 1) set("gender","男性");
    else set("gender","女性");
    set("title",me_guodu);
    set("age",20+random(100));
    set("per",18+random(5));
    set("attitude","friendly");
    set("no_refresh",1); // 不会被房间更新。
    set("inquiry",([
        "all": (: ask_all :),
        ask_arg : (: ask_baowu :),
        "宝物" : (:  ask_baowu :),
        ]));
    set("hj_game/npc", me_mark[0]);
    set("host_id","no");
    set("msg", HIW"只见一个人影渐渐清晰，终于凭空出现了一个陌生的人。\n"NOR);

        set("chat_chance", 1);
        set("chat_msg", ({ (: wait_singsong :) }));

    setup();

    remove_call_out("checking");
    remove_call_out("delete_me");
    call_out("checking", 1);
    call_out("delete_me",2400+random(600) ); // 降低游戏难度，40 - 50分钟内消失。
// 若七星灯内的设置 deng_time 为 300 的话，这里需要恢复为 1800+random(600) 。

}

// 如果该NPC的隶属玩家不存在或已退出游戏，本NPC清除。
void checking()
{
    object my_host;

    if( !environment( this_object() ) ) return;

    my_host=find_player(query("host_id"));
    if(!my_host || !my_host->query_temp("huanjing") ||
       my_host->query_temp("huanjing") !="start" ||
       !my_host->query_temp("hj_hp") || !my_host->query_temp("hj_hp_max") ||
       my_host->query_temp("hj_find_ok") == "yes")
    {
        remove_call_out("delete_me");
        call_out("delete_me",5);
    }

    else
    {
        remove_call_out("checking");
        call_out("checking",1);
    }
}

int ask_all()
{
    command("smile");
    command("say 我所知的如山之高，如海之深，你能听得完么？");
    return 1;
}

void wait_singsong()
{
    if( singing == 0 )
    {
        remove_call_out("sing_song");
        i=0;
        singing=1;
        if(random(3) == 1) songs=songs1;
        else if(random(3) == 1) songs=songs2;
        else songs=songs3;
        message_vision(CYN"$N"NOR+CYN"微微一笑，轻声唱起了歌来。\n"NOR,this_object());
        call_out("sing_song",2);
    }
}

void sing_song()
{
    message_vision(CYN"      "+songs[i]+"\n"NOR,this_object());
    i++;

    if( i < sizeof(songs) )
    {
        remove_call_out("sing_song");
        call_out("sing_song",3);
    }
    else
    {
        remove_call_out("song_over");
        call_out("song_over",2);
    }
}

void song_over()
{
    message_vision(CYN"\n$N"NOR+CYN"唱罢，又是微微一笑，似是想起许多往事。\n"NOR,this_object());
    singing=0;
}

void delete_me()
{
    object my_host;

    if( !environment( this_object() ) ) return;

    my_host=find_player(query("host_id"));
    if(my_host && my_host->query_temp("huanjing") =="start" &&
       my_host->query_temp("hj_find_ok") != "yes" )
        tell_object(my_host,HIR"你心中似乎掠过一丝不安，却又不知道为什么。\n"NOR);

    message_vision(HIW"$N"HIW"似乎满心失落地张望了一下，摇了摇头，忽地消失不见了。\n"NOR,this_object());
    remove_call_out("sing_song");
    destruct(this_object());
}

int ask_baowu()
{
    object me,tianma_zhishen,ob,obj1,obj2,gem_npc,my_gem,gem_rooms;
    int temp_i;
    string gem_name,gem_id;

    if( !environment(this_player())->query("room_mark") && !wizardp(this_player()))
        return 0;

    me=this_player();
    ob=this_object();

    if( !me->query_temp("huanjing") || me->query_temp("huanjing") != "start" ||
        !me->query_temp("hj_hp") || me->query_temp("hj_hp") < 1 )
        return 0;

    if( singing == 1) 
    {
        write(ob->query("name")+"正在唱歌呢，哪里有空回答你呀。\n");
        return 1;
    }

    if( ob->query("host_id") != me->query("id") )
    {
        message_vision(CYN"$N"NOR+CYN"微微笑了一笑，却并不说话。\n"NOR,ob);
        return 1;
    }

    obj1=present(me_mark[1],me);
    obj2=present(me_mark[2],me);


// 玩家要起码带上其他两个组合部分在身上才能继续
// 而且，必须是自己的宝物才行
// 下调，带上一个即可

    if(!obj1 && !obj2)
    {
        message_vision(CYN"$N"NOR+CYN"似乎刚说点什么，忽地想起什么似的微微笑了一笑，却又不说话了。\n"NOR,ob);
        return 1;
    }

    if(obj1 && obj1->query("host_id") !=me->query("id") )
    {
        command("say 这"+obj1->query("name")+NOR+CYN"并不是你的。你怎么拿了别人的东西？");
        return 1;
    }

    if(obj2 && obj2->query("host_id") !=me->query("id") )
    {
        command("say 这"+obj2->query("name")+NOR+CYN"并不是你的。你怎么拿了别人的东西？");
        return 1;
    }

    if( !me->query_temp("hj_find_gem/name") || !me->query_temp("hj_find_gem/id") )
    {
        temp_i=random(5);
        if(temp_i >= sizeof(gem_names) )
            temp_i = sizeof(gem_names) -1;
        gem_name = gem_names[temp_i];
        gem_id = gem_ids[temp_i];

        command("say 你若能寻得"+gem_name+"，我将予你我的国度的宝物。");
        me->set_temp("hj_find_gem/name",gem_name);
        me->set_temp("hj_find_gem/id",gem_id);
        command("smile "+me->query("id"));

        gem_npc=new(__DIR__"hj_npc_kill");

        gem_npc->set("delete_time_max",1800);  // 此带宝NPC最多半小时后清除
        gem_npc->set("take_gem_npc","yes");
        gem_npc->set("the_gem_for",me->query("id"));
        gem_npc->setme( temp_i );

        temp_i=1+random( HJ_ROOM_AMOUNT );
        gem_rooms=find_object( HJ_DIR +"hj_room"+temp_i);
        if(!gem_rooms) gem_rooms=load_object( HJ_DIR +"hj_room"+temp_i);
        gem_npc->move(gem_rooms);
        if(gem_npc->query("msg")) tell_room(gem_rooms,gem_npc->query("msg"));
        else tell_room(gem_rooms,gem_npc->query("name")+"走了过来。\n");
        return 1;
    }

    my_gem=present(me->query_temp("hj_find_gem/id") , me);
    if(!my_gem)
    {
        command("say 你还未寻得"+me->query_temp("hj_find_gem/name")+"啊。");
        command("pat "+me->query("id"));
        return 1;
    }

// 成功寻到该族宝物
    baowu=new(baowu_dir);
    baowu->set("host_id",me->query("id"));
    baowu->setme( 0 );
    baowu->move(me);

    message_vision(CYN"$N"NOR+CYN"拿出一个"+my_gem->query("name")+NOR+CYN"递给了"+ob->query("name")+NOR+CYN"。\n",me);
    destruct(my_gem);
    command("idle2");
    message_vision( CYN"$n"NOR+CYN"微微一笑，把一个"+baowu->query("name")+NOR+CYN"递给了$N"NOR+CYN"。\n"NOR, me, ob);

// 新添物品“幽灵之令”，可在 hj_room1.c 快速得到幽灵武士JOB。

    baowu = new( __DIR__"hj_obj_ylling" );
    baowu ->set("my_master", me);
    baowu ->set("this_time_mark", me->query_temp("this_time_mark") );
    baowu ->set("long",
        baowu->query("long") + "它上面似乎刻着个细细的名字："+me->query("id") + "\n");
    baowu ->delete("waiting_set");
    baowu ->move(me);

    message_vision( CYN"$n"NOR+CYN"又拿出了一个"+baowu->query("name")+NOR+CYN"递给了$N"NOR+CYN"。\n"NOR,me,ob);
    command( "say “近日林中竟有幽灵族人现身，请带上这个令牌，或有些许帮助。”");
    message_vision(CYN"$N"NOR+CYN"说完，身影突然朦胧，竟然就此消失不见！\n"NOR,ob);
    message_vision(CYN"$N"NOR+CYN"细细思索着，一时间竟然呆住了。\n"NOR,me);
    me->start_busy(10+random(10));   // 此时有极高的忙时，并且有怪物出现要打

    temp_i = 3;
    while( temp_i -- )
    {
        if(random(3))
        {
            baowu = new(__DIR__"hj_npc_kill");
            baowu -> set("killme_by", me->query("id") );
            baowu ->move(environment(me));
            message_vision( "$N快步走了过来！\n", baowu);
        }
    }

    singing=1; 
// 这个可以作应急判断，当这wait delete 的短短一秒里，可以保证不再执行任何函数 :)
    remove_call_out("sing_song");
    destruct(this_object());
    return 1;
}
