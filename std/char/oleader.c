#include <dbase.h>
#include <login.h>
#include <ansi.h>
/*
int prevent_learn(object me, string skill)
{
    mapping my_family, family;
    int	betrayer, mylvl, lvl;

    lvl = this_object()->query_skill(skill, 1);
    mylvl = me->query_skill(skill, 1);
    if( betrayer = me->query("betrayer") )
    {
        if( mylvl >= lvl - betrayer * 20 )
        {
            message_vision("$N神色间似乎对$n不是十分信任，\n"
                           "也许是想起$p从前背叛师门的事情\n...。\n",
                           this_object(), me );
            command("say 嗯 .... \n师父能教你的都教了，其他的你自己练吧。");
            return 1;
        }
    }

    if( !me->is_apprentice_of(this_object()))
    {
        if( !mapp(my_family = me->query("family")) )  return 0;
        if( !mapp(family = this_object()->query("family")) ) return 0;
        if((my_family["family_name"] == family["family_name"]) )
        {
            command("hmm");
            command("pat " + me->query("id"));
            command("say 虽然你我同门，可是你并非我的弟子，"
                    "你还是去找你师父学吧....");
            return 1;
        }
    }

    return 0;
}
*/

string org_rank_title(object member)
{
    int exp,i,gen;
    string* ranks;
    int * rank_levels;
    string org_title;

    ranks=query("org_ranks");
    rank_levels=query("org_rank_levels");
    if(!arrayp(rank_levels))
        rank_levels= ({1000000,5000000,10000000});
    
    if(!arrayp(ranks) || sizeof(rank_levels)+1 != sizeof(ranks))
    {
        if(!org_title = query("org_title"))
            org_title = "成员";
    }        
    else
    {
        exp = (int) member->query("combat_exp");
        for(i=0;i<sizeof(rank_levels);i++)
            if(exp < rank_levels[i]) break;
        org_title=ranks[i];
    }
    // if(!stringp(ranks[i])) title=?
    return org_title;
}

void org_rerank(object member)
{
     mapping organization;
    if( !mapp(organization = query("organization")) ) return;
	//organization["org_title"] = org_rank_title(member);
	member->set("organization/org_title", org_rank_title(member));
	return ;
} 

int enroll_member(object ob)
{
    mapping my_organization, organization;
    if( ob->is_member_of( this_object() ) )	return 0;
    if( !mapp(my_organization = query("organization")) ) return 0;
	if (mapp(ob->query("organization"))) ob->delete("organization");
    organization = allocate_mapping(sizeof(my_organization));
    organization["leader_id"] = query("id");
    organization["leader_name"] = query("name");
    organization["org_name"] = my_organization["org_name"];
    organization["generation"] = my_organization["generation"] + 1;
	organization["org_attribute"] = my_organization["org_attribute"];
    organization["enter_time"] = time();
    // privs = 0 for general 
    organization["privs"] = 0;
    ob->set("organization", organization);
    //ob->set("class", query("class"));
    org_rerank(ob);
    return 1;
}
