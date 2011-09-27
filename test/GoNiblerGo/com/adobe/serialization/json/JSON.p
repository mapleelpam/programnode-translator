
program 
  statementlist 
    config namespace  
      identifier CONFIG 
    import  
      packagename 
        packageidentifiers 
          identifier __AS3__
          identifier vec
          identifier Vector
    package 
      packagename 
        packageidentifiers 
          identifier com
          identifier adobe
          identifier serialization
          identifier json
    import  
      packagename 
        packageidentifiers 
          identifier __AS3__
          identifier vec
          identifier Vector
    class 
      attributelist 
        member 
          get lexical 
            identifier final
        list 
          member 
            get lexical 
              identifier public
      qualifiedidentifier JSON 
        qualifier 
          attributelist 
            member 
              get lexical 
                identifier final
            list 
              member 
                get lexical 
                  identifier public
      statementlist 
        function 
          attributelist 
            member 
              get lexical 
                identifier static
            list 
              member 
                get lexical 
                  identifier public
          functionname 
            qualifiedidentifier encode 
              qualifier 
                attributelist 
                  member 
                    get lexical 
                      identifier static
                  list 
                    member 
                      get lexical 
                        identifier public
          functioncommon 
            functionsignature 
              parameterlist 
                parameter 
                  identifier o
                  typeexpr 
                    member 
                      get lexical 
                        identifier Object
              typeexpr 
                member 
                  get lexical 
                    identifier String
            statementlist 
              return 
                list 
                  member 
                    member 
                      construct lexical 
                        identifier JSONEncoder
                        argumentlist 
                          member 
                            get lexical 
                              identifier o
                    call dot 
                      identifier getString
              return 
        function 
          attributelist 
            member 
              get lexical 
                identifier static
            list 
              member 
                get lexical 
                  identifier public
          functionname 
            qualifiedidentifier decode 
              qualifier 
                attributelist 
                  member 
                    get lexical 
                      identifier static
                  list 
                    member 
                      get lexical 
                        identifier public
          functioncommon 
            functionsignature 
              parameterlist 
                parameter 
                  identifier s
                  typeexpr 
                    member 
                      get lexical 
                        identifier String
                parameter 
                  identifier strict
                  literalboolean 1
                  typeexpr 
                    member 
                      get lexical 
                        identifier Boolean
            statementlist 
              return 
                list 
                  member 
                    member 
                      construct lexical 
                        identifier JSONDecoder
                        argumentlist 
                          member 
                            get lexical 
                              identifier s
                          member 
                            get lexical 
                              identifier strict
                    call dot 
                      identifier getValue
              return 
    package 
      packagename 
        packageidentifiers 
          identifier com
          identifier adobe
          identifier serialization
          identifier json
