// apprentice.c

#include <dbase.h>

int is_apprentice_of(object ob)
{
    	mapping family;
    
    	if( !mapp(family = query("family")) ) return 0;
    
    	return( family["master_id"] == (string)ob->query("id")
        	&& family["master_name"] == (string)ob->query("name") 
        	&& family["family_name"] == (string)ob->query("family/family_name")
        	&& ob->query("family/privs") == -1 );
}

int is_couple_of(object ob)
{
    	if((string)query("marry") == (string)ob->query("id") &&
       		(string)query("id") == (string)ob->query("marry"))
		return 1;
    	return 0;
}

varargs void assign_title(string title, int nogen)
{
    	mapping family;
    	int gen;
    	if( !mapp(family = query("family")) ) return;

    	family["title"]=title;
    	if(!nogen)
    	{
        	gen=family["generation"];
        //self set rank_nogen can override assign_title's arg
        	if(gen > 1 && query("rank_nogen")==0)
            	title=sprintf("第%s代%s", chinese_number(gen), title);
    	}
    	set("title",family["family_name"]+" "+title);
    
}

// This is used for NPC, or start a new family for a player.
void create_family(string family_name, int generation, string title)
{
    	mapping family;
    
    	family = allocate_mapping(6);
    
    	family["family_name"] = family_name;
    	family["generation"] = generation;
    // priv = -1 for ALL privileges.
    	family["privs"] = -1;
    	set("family", family);
        assign_title(title);
}

//the following functions are used for organization 
//check if the player is a member of a certain organization
int is_member_of(object ob)
{
    	mapping organization;
    
    	if( !mapp(organization = query("organization")) ) return 0;
    
    	return( organization["leader_id"] == (string)ob->query("id")
        	&& organization["leader_name"] == (string)ob->query("name") 
        	&& organization["org_name"] == (string)ob->query("organization/org_name")
        	&& ob->query("organization/privs") == -1 );
}

//this will be used for NPC organization, or start a new Organization for a player
void create_organization(string org_name,int generation, string org_attribute )
{
    	mapping organization;
    
    	organization = allocate_mapping(4);
    	
    	organization["org_name"] = org_name;
    	organization["generation"] = generation;
	organization["org_attribute"] = org_attribute;
    	// priv = -1 for ALL privileges.
    	organization["privs"] = -1;
    	set("organization", organization);
}


string org_rank_title(object member)
{
    	int exp,i/*,gen*/;
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

