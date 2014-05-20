/*
 * ml-lib, a machine learning library for Max and Pure Data
 * Copyright (C) 2013 Carnegie Mellon University
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ml_classification.h"

namespace ml
{
    static const std::string ml_object_name = "ml.lda";
    
    // Utility functions
    
    
    // Class declaration
    class ml_lda : ml_classification
    {
        FLEXT_HEADER_S(ml_lda, ml, setup);
        
    public:
        ml_lda()
        {
            post("LDA algorithm based on the GRT library version " + get_grt_version());
            set_scaling(default_scaling);
        }
        
        ~ml_lda()
        {
            
        }
        
    protected:
        static void setup(t_classid c)
        {
            // Flext attribute set messages
            
            // Flext attribute get messages
            
            // Flext method messages
            
            // Associate this Flext class with a certain help file prefix
            DefineHelp(c, ml_object_name.c_str());
        }
        
        // Methods
        
        // Attribute Setters
        
        // Attribute Getters
        
        // Pure virtual method implementations
        GRT::Classifier &get_Classifier_instance();
        const GRT::Classifier &get_Classifier_instance() const;
        
    private:
        // Flext method wrappers
        
        // Flext attribute wrappers
        
        // Virtual method override
        virtual const std::string get_object_name(void) const { return ml_object_name; };
        
        // Instance variables
        GRT::LDA lda;
    };
    
    // Utility functions
        
    // Attribute setters
    
    // Attribute getters
    
    // Methods
    
    // Implement pure virtual methods
    GRT::Classifier &ml_lda::get_Classifier_instance()
    {
        return lda;
    }
    
    const GRT::Classifier &ml_lda::get_Classifier_instance() const
    {
        return lda;
    }
    
    FLEXT_LIB(ml_object_name.c_str(), ml_lda);
    
} //namespace ml


