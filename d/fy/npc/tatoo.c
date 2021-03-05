#include <ansi.h> 
inherit NPC;

int do_tatoo(string arg);
int ask_tatoo();

void create()
{
    set_name("妖雪", ({"hex"}));
    set("long","
妖雪的来历没人清楚，也没人知道这样一个漂亮小姑娘凭什么能安安全全
地行走江湖。登徒浪子，地痞流氓，似乎都乖乖地离她远远的，也许是怕
了她手中那三寸长的乌针。妖雪那纹身的技艺，也是远近小有名气的，相
传你描述的出来，她都愿意纹，纹什么像什么，这么好的手艺，自然价格
也不菲，你要是感兴趣，可以向她打听［纹身］试试看。
\n\n");
        set("gender","女性");
      set("title", CYN"小脚丫 走四方"NOR);
        set("age",18);
        set("agi",50);
        set("str",20);
        set("per",50);        
        set("NO_KILL",1);
        set("combat_exp", 100);
        set("attitude", "friendly");        
        set("chat_chance", 1);
        set("chat_msg", ({
             (: random_move :),
         }) );  
        set("inquiry", ([       
                "纹身":     (: ask_tatoo :),
                "tatoo":    (: ask_tatoo :),    
         ]));
        setup();
        carry_object("/obj/armor/cloth",
              (["name": MAG"粉色轻纱"NOR,
     ]))->wear();  
        carry_object("/d/qianfo/npc/obj/needle",
              (["name": BLK"三寸长的乌针"NOR,
                "value": 0,
     ]))->wield();       
}
 
void init(){
add_action("do_tatoo","tatoo");
::init();
}

int ask_tatoo()
{
  object me;
me = this_player();
if (me->query("gender") == "女性") {
  tell_object(me,CYN"妖雪睁着大眼睛望着你：这位姐姐想纹些什么？只要和我说（tatoo <描述>），我都能帮你纹。\n一点都不疼。姐姐你这么漂亮，便宜点，一两黄金就好了。\n"NOR);
}else{
tell_object(me,CYN"妖雪犹犹豫豫地盯着你一会，说道：这位大哥哥想纹些什么？拿定主意了和我说一声（tatoo <描述>）。\n价格是一两黄金，不过。。。男女授受不亲，麻烦您还是避免些尴尬的地方\n"NOR);
  }
  return 1;
}

int do_tatoo(string arg)
{
object me;
me = this_player();

  if( !arg ) {
    return notify_fail(CYN"指令格式 : tatoo <描述>\n"NOR);
   }
   
  if( strlen(arg) > 40 ) {
    ccommand("lazy");
    return notify_fail(CYN"妖雪打了个呵欠：你要纹的太麻烦了。\n"NOR);
   }   
   
  if (me->query("deposit")<10000)
    return notify_fail("你的存款不足一两黄金。\n");

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        me->set_temp("body_print", arg + NOR);
        me->add("deposit",-10000);
   tell_object(me,CYN"妖雪擦了擦头上的汗：好啦好啦，不过你怕疼，我下手轻了些，时间久了难保不会淡去。\n"NOR);

  return 1;
}
